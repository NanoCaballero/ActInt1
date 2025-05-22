# CMakeLists.txt para la Actividad Integradora 1

cmake_minimum_required(VERSION 3.30)

# Nombre del proyecto
project(Actividad_Integradora_1 VERSION 1.0.0 LANGUAGES C CXX)

# Configuración global
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Incluir archivos de cabecera del proyecto
include_directories(${CMAKE_SOURCE_DIR})

# Archivos fuente principales
set(SOURCES
    main.cpp
)

# Crear el ejecutable principal
add_executable(Actividad_Integradora_1 ${SOURCES})

# Opciones
option(ENABLE_TESTING "Enable Unit Testing" ON)
option(ENABLE_COVERAGE "Enable coverage reporting" ON)

# Activar cobertura si está habilitada
if (ENABLE_COVERAGE)
    message(STATUS "Activando flags de cobertura")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage -fprofile-arcs -ftest-coverage")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
endif()

# Descargar GoogleTest
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.11.0
)
FetchContent_MakeAvailable(googletest)

# Configuración de pruebas
if (ENABLE_TESTING)
    enable_testing()

    function(add_test_executable name source)
        add_executable(${name} ${source})
        target_link_libraries(${name} PRIVATE gtest gtest_main)
        if (ENABLE_COVERAGE)
            target_link_libraries(${name} PRIVATE gcov)
            target_compile_options(${name} PRIVATE --coverage -fprofile-arcs -ftest-coverage)
            target_link_options(${name} PRIVATE --coverage)
        endif()
        add_test(NAME ${name} COMMAND ${name})
    endfunction()

    # Ruta del archivo de prueba
    add_test_executable(test/transmission_test.cpp)

    # Tarea para generar cobertura con lcov
    if (ENABLE_COVERAGE)
        find_program(LCOV lcov)
        if (LCOV)
            add_custom_target(coverage
                COMMAND lcov --capture --directory . --output-file build/coverage.info
                COMMAND genhtml build/coverage.info --output-directory build/coverage_html
                COMMENT "Generando reporte de cobertura con lcov"
                VERBATIM
            )
        else()
            message(WARNING "LCOV no encontrado. No se podrá generar el reporte de cobertura.")
        endif()
    endif()
endif()
