cmake_minimum_required(VERSION 3.16)
project(HinaPE_py)
if (APPLE)
    enable_language(OBJC)
endif ()
# add_subdirectory(HinaPE)
add_subdirectory(pybind11)
pybind11_add_module(HinaPE_py src/main.cpp)
# EXAMPLE_VERSION_INFO is defined by setup.py and passed into the C++ code
target_compile_definitions(HinaPE_py PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})

find_package(Python 3.10...<3.11 COMPONENTS Interpreter Development REQUIRED)
target_include_directories(HinaPE_py PUBLIC ${Python_INCLUDE_DIRS})
