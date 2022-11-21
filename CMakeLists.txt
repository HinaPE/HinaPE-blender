cmake_minimum_required(VERSION 3.16)
project(Hina)
if (APPLE)
    enable_language(OBJC)
endif ()
# add_subdirectory(HinaPE)
add_subdirectory(pybind11)
pybind11_add_module(Hina src/main.cpp)
# EXAMPLE_VERSION_INFO is defined by setup.py and passed into the C++ code
target_compile_definitions(Hina PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})

find_package(Python 3.10...<3.11 COMPONENTS Interpreter Development REQUIRED)
target_include_directories(Hina PUBLIC ${Python_INCLUDE_DIRS})
