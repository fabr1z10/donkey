cmake_minimum_required(VERSION 3.4...3.18)
project(cmake_example)
message(STATUS "miniotta")


add_subdirectory(pybind11)


add_subdirectory(libpng)
add_subdirectory(libjpeg)

#find_package(PNG REQUIRED)

pybind11_add_module(cmake_example src/main.cpp)

message(STATUS "suca")
message(STATUS ${PNG_LIBRARY})
target_link_libraries(cmake_example PUBLIC png jpeg) #${PNG_LIBRARY})
# EXAMPLE_VERSION_INFO is defined by setup.py and passed into the C++ code as a
# define (VERSION_INFO) here.
#target_compile_definitions(cmake_example PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})

