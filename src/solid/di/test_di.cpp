#include "database.hpp"
#include "di_concepts.hpp"
#include "http_client.hpp"
#include "microservice.hpp"
#include "yaml.hpp"

namespace v1 {
    void test_di() {
        microservice srv;
        srv.process("data");
    }
}

namespace v2 {
    void test_di() {
        // Register
        http_client transport{"https://web.api.v1", 443};
        yaml_formatter format;
        database persistence{"Data Source=:memory:", "DB"};

        // Resolve
        microservice srv(transport, format, persistence);

        // Use
        srv.process("data");
    }
}