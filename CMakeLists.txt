cmake_minimum_required(VERSION 3.10)
project(LeetCode CXX)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCE_FILES "*.cpp")

foreach(file ${SOURCE_FILES})
    get_filename_component(filename ${file} NAME_WE)
    add_executable(${filename} ${file})
endforeach()
