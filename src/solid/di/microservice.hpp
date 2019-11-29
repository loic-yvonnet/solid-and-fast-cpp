#ifndef MICROSERVICE_HPP
#define MICROSERVICE_HPP

#include "crtp.hpp"
#include "database.hpp"
#include "http_client.hpp"
#include "yaml.hpp"
#include "di_concepts.hpp"

#include <string_view>
#include <stdexcept>
#include <tuple>
#include <variant>

template <typename TDerived>
class microservice_base : public crtp<TDerived, microservice_base> {
    microservice_base() = default;
    friend TDerived;

    http::response send_request(std::string_view data) {
        const auto response = this->underlying().transport.send({
            http::verb::POST,
            "/resource",
            {{"Accept", "text/x-yaml"}},
            data.data()
        });

        if (response.code != http::OK) { throw std::runtime_error("..."); }

        return response;
    }

    std::tuple<std::string, std::string> deserialize(std::string_view payload) {
        yaml_formatter& format = this->underlying().format;
        const auto yaml_object = format.deserialize(payload);

        return std::make_tuple(
            yaml_object.at<std::string>("key"),
            yaml_object.at<std::string>("value")
        );
    }

    void store(std::string_view key, std::string_view value) {
        this->underlying().persistence.query(R"(
            INSERT INTO table ({})
            VALUES('{}')
        )", key, value);
    }

public:
    void process(std::string_view data) {
        const auto response = send_request(data);       // use transport
        auto [key, value] = deserialize(response.body); // use format
        store(key, value);                              // use persistence
    }
};

namespace v1 {
    class microservice : public microservice_base<microservice> {
        http_client transport{"https://web.api.v1", 443};
        yaml_formatter format;
        database persistence{"Data Source=:memory:", "DB"};

        friend class microservice_base<microservice>;
    };
}

namespace v2 {
    template <
        concepts::http_client<http::request, http::response>                  TTransport   = http_client,
        concepts::yaml_formatter<yaml::object, std::string>                   TFormatter   = yaml_formatter,
        concepts::database<db::result, std::string, std::string, std::string> TPersistence = database
    >
    class microservice : public microservice_base<microservice<TTransport, TFormatter, TPersistence>> {
        TTransport transport;
        TFormatter format;
        TPersistence persistence;

        friend class microservice_base<microservice>;

    public:
        explicit microservice(const TTransport& t, const TFormatter& f, const TPersistence& p) :
            transport{t}, format{f}, persistence{p} {}
    };
}

#endif