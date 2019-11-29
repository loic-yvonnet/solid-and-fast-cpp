#ifndef HTTP_CLIENT_HPP
#define HTTP_CLIENT_HPP

#include <string>
#include <unordered_map>

namespace http {
    constexpr short OK = 200;

    enum class verb {
        GET,
        POST,
        PUT,
        PATCH,
        DELETE,
        OPTIONS
    };

    using headers_t = std::unordered_map<std::string, std::string>;

    struct request {
        verb action{verb::GET};
        std::string url;
        headers_t headers;
        std::string body;
    };

    struct response {
        short code;
        headers_t headers;
        std::string body;
    };
}

class http_client final {
public:
    explicit http_client([[maybe_unused]] std::string_view host,
                         [[maybe_unused]] short port) {}

    [[nodiscard]] http::response send([[maybe_unused]]const http::request& request) const {
        return { 0, {}, "" };
    }
};

#endif