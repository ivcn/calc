cmake_minimum_required (VERSION 3.5)

project(Calc CXX)

include_directories("${PROJECT_SOURCE_DIR}")

add_executable(calc main.cpp calc.cpp)
add_executable(test_calc test.cpp calc.cpp)
set_property(TARGET calc test_calc PROPERTY CXX_STANDARD 11)
