#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <string_view>
#include <string>
#include <unordered_map>
#include <variant>
#include <vector>

namespace db {
    using key = std::string;
    using value = std::variant<bool, long, double, std::string>;
    using row = std::unordered_map<key, value>;
    using result = std::vector<row>;
}

class database final {
public:
    explicit database([[maybe_unused]] std::string_view connection,
                      [[maybe_unused]] std::string_view db_name) {}

    template <typename... TArgs>
    db::result query([[maybe_unused]] std::string_view sql, [[maybe_unused]] TArgs&&... args) {
        return {};
    }
};

#endif