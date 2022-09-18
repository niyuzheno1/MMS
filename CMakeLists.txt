cmake_minimum_required(VERSION 3.0)

project(MMS VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(MMS_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(MMS_HEADER_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(MMS_EXPORT_HEADER_DIR "${CMAKE_CURRENT_SOURCE_DIR}/export_headers")


file(GLOB_RECURSE  MMS_SOURCE_FILES
     "${MMS_SOURCE_DIR}/*.cpp"
     "${MMS_HEADER_DIR}/*.h"
      "${MMS_EXPORT_HEADER_DIR}/*.h"
     "${MMS_SOURCE_DIR}/*.c"
     )

add_subdirectory(MMS_Library)
list(APPEND EXTRA_LIBS MMS_Library)

add_executable(FileSerializationPrototype ${MMS_SOURCE_FILES})
target_include_directories(FileSerializationPrototype PUBLIC "${MMS_HEADER_DIR}")
target_include_directories(FileSerializationPrototype PUBLIC "${MMS_EXPORT_HEADER_DIR}")
target_link_libraries(FileSerializationPrototype ${EXTRA_LIBS})
target_include_directories(FileSerializationPrototype PUBLIC ${PROJECT_BINARY_DIR}/include)