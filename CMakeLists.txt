cmake_minimum_required(VERSION 3.24)
project(flappy_bird)

set(CMAKE_CXX_STANDARD 17)

add_executable(flappy_bird src/main.cpp src/State.h src/State.h src/StateMachine.cpp src/StateMachine.h src/StateMachine.h src/AssetManager.cpp src/AssetManager.h src/InputManager.cpp src/InputManager.h src/InputManager.h src/Game.cpp src/Game.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:\\SFML\\lib\\cmake\\SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:\\SFML\\include\\SFML)
target_link_libraries(flappy_bird sfml-system sfml-window sfml-graphics sfml-audio)