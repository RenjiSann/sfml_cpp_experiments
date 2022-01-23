cmake_minimum_required(VERSION 3.21)
project(cpp_sfml)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 14)

include_directories(pendulum)
add_executable(cpp_sfml
        pendulum/double_pendulum.cpp
        pendulum/double_pendulum.hpp
        pendulum/main.cpp
        pendulum/pendulum_display.cpp
        pendulum/pendulum_display.hpp
        pendulum/pendulum_drawing.cpp
        pendulum/pendulum_drawing.hpp
        pendulum/simple_pendulum.cpp
        pendulum/simple_pendulum.hpp
        pendulum/utils.cpp
        pendulum/utils.hpp)

target_link_libraries(cpp_sfml sfml-window sfml-graphics sfml-system)
