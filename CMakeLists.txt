cmake_minimum_required(VERSION 3.30)
project(Actividad_Integradora_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Actividad_Integradora_1 main.cpp)

add_executable(test_transmission test/test_transmission.cpp)
target_link_libraries(test_transmission gcov)
target_compile_options(test_transmission PRIVATE --coverage)
target_link_options(test_transmission PRIVATE --coverage)
add_test(NAME test_transmission COMMAND test_transmission)
