cmake_minimum_required(VERSION 3.16)
project(HinaPE_py)
find_package(Python 3.10...<3.11 COMPONENTS Interpreter Development REQUIRED)
if (APPLE)
    enable_language(OBJC)
endif ()
if (MSVC)
    set(PythonLibsNew_Dir ${Python_LIBRARY_DIRS})
endif ()
add_subdirectory(HinaPE)
add_subdirectory(pybind11)
pybind11_add_module(HinaPE_py src/main.cpp src/free_fall.h src/free_fall.cpp)
set_target_properties(HinaPE_py PROPERTIES CXX_STANDARD 20 CXX_EXTENSIONS OFF)
# EXAMPLE_VERSION_INFO is defined by setup.py and passed into the C++ code
target_compile_definitions(HinaPE_py PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})
target_include_directories(HinaPE_py PUBLIC ${Python_INCLUDE_DIRS})
target_include_directories(HinaPE_py PUBLIC ${HINAPE_COMMON_DIR})
target_link_libraries(HinaPE_py PUBLIC HinaPE_Common)
