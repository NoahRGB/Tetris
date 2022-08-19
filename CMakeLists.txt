cmake_minimum_required(VERSION 3.14)
project(SFMLGame)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(SFMLGame src/main.cpp src/tetromino.hpp src/tetromino.cpp src/block.hpp src/block.cpp src/line.hpp src/line.cpp src/t.hpp src/t.cpp src/l.hpp src/l.cpp src/s.hpp src/s.cpp src/z.hpp src/z.cpp src/j.hpp src/j.cpp src/tools.hpp src/tools.cpp)

include_directories(/usr/local/include)
target_include_directories(SFMLGame PRIVATE ./src)

find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

include_directories(${SFML_INCLUDE_DIRS})


target_link_libraries(SFMLGame sfml-system sfml-window sfml-graphics)