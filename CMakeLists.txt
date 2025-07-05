cmake_minimum_required(VERSION 3.25)
project(Competitive)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE cpp_files CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/*.cpp)

foreach(file ${cpp_files})
    file(RELATIVE_PATH rel_path ${CMAKE_SOURCE_DIR} ${file})

    # Replace '/' and '.' with '_'
    string(REGEX REPLACE "[/. ]" "_" target_name "${rel_path}")

    # Remove any other problematic characters (optional hardening)
    string(REGEX REPLACE "[^A-Za-z0-9_]" "" target_name "${target_name}")

    add_executable(${target_name} ${file})
endforeach()