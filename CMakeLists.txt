cmake_minimum_required(VERSION 3.24)
project(flappy_bird)

set(CMAKE_CXX_STANDARD 17)

add_executable(flappy_bird src/main.cpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:\\SFML\\lib\\cmake\\SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:\\SFML\\include\\SFML)
target_link_libraries(flappy_bird sfml-system sfml-window sfml-graphics sfml-audio)