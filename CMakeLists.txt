cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(GCC_COMPILE_FLAGS "-Wall -Wextra -Werror -Wsuggest-override -Wno-register -Wno-missing-braces -Wno-unknown-pragmas -fdiagnostics-show-option")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COMPILE_FLAGS}")

project(fast VERSION 0.0.2)

add_executable(fast
                    src/main.cpp
                    src/fast/functional/new_const_qualifiers.cpp
                    src/fast/functional/repeat_n.hpp
                    src/fast/functional/test_repeat_n.cpp
                    src/solid/single_resp/griffin.hpp
                    src/solid/single_resp/eagle.hpp
                    src/solid/single_resp/lion.hpp
                    src/solid/single_resp/horse.hpp
                    src/solid/open_close/helicopter.hpp
                    src/solid/open_close/maneuverable.hpp
                    src/solid/open_close/tactics.hpp
                    src/solid/open_close/tank.hpp
                    src/solid/open_close/test_maneuver.cpp
                    src/solid/liskov/lsp_problem.hpp
                    src/solid/liskov/test_lsp.cpp
                    src/solid/itf_segregation/chimera_concept.hpp
                    src/solid/di/crtp.hpp
                    src/solid/di/database.hpp
                    src/solid/di/di_concepts.hpp
                    src/solid/di/http_client.hpp
                    src/solid/di/microservice.hpp
                    src/solid/di/test_di.cpp
                    src/solid/di/yaml.hpp
)
