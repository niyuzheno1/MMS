cmake_minimum_required (VERSION 3.16)
project(MMS_Library VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

file(GLOB_RECURSE  MMS_SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/include/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/*.c
     )
    



add_library(MMS_Library ${MMS_SOURCE_FILES})
target_include_directories(MMS_Library  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(MMS_Library  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/export_headers)
