cmake_minimum_required(VERSION 3.30)
project(transmission_project VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Incluir headers
include_directories(${CMAKE_SOURCE_DIR})

option(ENABLE_COVERAGE "Enable coverage reporting" ON)

if (ENABLE_COVERAGE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage -fprofile-arcs -ftest-coverage")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
endif()

# Ejecutable principal
add_executable(main main.cpp)

# GoogleTest setup
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.11.0
)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Archivo de pruebas
add_executable(test_transmission test/test_transmission.cpp)
target_link_libraries(test_transmission gtest gtest_main)

if (ENABLE_COVERAGE)
    target_link_libraries(test_transmission gcov)
    target_compile_options(test_transmission PRIVATE --coverage -fprofile-arcs -ftest-coverage)
    target_link_options(test_transmission PRIVATE --coverage)
endif()

add_test(NAME test_transmission COMMAND test_transmission)
