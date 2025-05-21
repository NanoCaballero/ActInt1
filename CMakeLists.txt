cmake_minimum_required(VERSION 3.30)
project(sonarqube_unit_test VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Incluir headers del proyecto
include_directories(${CMAKE_SOURCE_DIR})

# Archivos fuente principales
set(SOURCES
    main.cpp
    transmission_utils.cpp
)

# Ejecutable principal
add_executable(Actividad_Integradora_1 ${SOURCES})

# Opciones para testing y cobertura
option(ENABLE_TESTING "Enable unit testing" ON)
option(ENABLE_COVERAGE "Enable coverage reporting" ON)

# Habilitar flags de cobertura si se solicita
if (ENABLE_COVERAGE)
    message(STATUS "Coverage enabled")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage -fprofile-arcs -ftest-coverage")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
endif()

# Descarga GoogleTest
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.11.0
)
FetchContent_MakeAvailable(googletest)

# Si se habilitan pruebas:
if (ENABLE_TESTING)
    enable_testing()

    # Función auxiliar para registrar ejecutables de test
    function(add_test_executable name source)
        add_executable(${name} ${source} transmission_utils.cpp)
        target_link_libraries(${name} PRIVATE gtest gtest_main)

        if (ENABLE_COVERAGE)
            target_link_libraries(${name} PRIVATE gcov)
            target_compile_options(${name} PRIVATE --coverage -fprofile-arcs -ftest-coverage)
            target_link_options(${name} PRIVATE --coverage)
        endif()

        add_test(NAME ${name} COMMAND ${name})
    endfunction()

    # Registrar los archivos de test
    add_test_executable(test_transmission test/test_transmission.cpp)

    # Target opcional para generar HTML con LCOV (no usado por SonarQube, pero útil localmente)
    if (ENABLE_COVERAGE)
        find_program(LCOV lcov)
        if (LCOV)
            add_custom_target(coverage
                COMMAND lcov --capture --directory . --output-file build/coverage.info
                COMMAND genhtml build/coverage.info --output-directory build/coverage_html
                COMMENT "Generating coverage report"
                VERBATIM
            )
        endif()
    endif()
endif()
