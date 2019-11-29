#ifndef YAML_HPP
#define YAML_HPP

#include <chrono>
#include <string>
#include <string_view>
#include <memory>
#include <variant>
#include <vector>
#include <unordered_map>

namespace yaml {
    using time = std::chrono::time_point<std::chrono::system_clock>;

    template <typename TObject, typename TValue>
    using variant = std::variant<
        std::monostate,
        bool,
        int,
        double,
        std::string,
        time,
        std::unique_ptr<TObject>,
        std::vector<TValue>
    >;

    template <typename TObject>
    struct value_type {
        variant<TObject, value_type> value;
    };

    using key = std::string;

    template <typename TObject>
    using node = std::unordered_map<key, value_type<TObject>>;

    struct object {
        node<object> attributes;

        template <typename T>
        T at(std::string_view k) const {
            return std::get<T>(attributes.at(k.data()).value);
        }
    };
}

struct yaml_formatter final {
    [[nodiscard]] std::string serialize(const yaml::object&) {
        return "";
    }

    [[nodiscard]] yaml::object deserialize(std::string_view) {
        return {};
    }
};

#endif