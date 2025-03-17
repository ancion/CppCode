cmake_minimum_required(VERSION 3.10.11)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


# 项目描述文件
project(ccpp VERSION 0.1.0 LANGUAGES C CXX)

include_directories(include)

aux_source_directory(src/*.cpp SOURCES)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/libs)

aux_source_directory(03-oop/ OOP)

add_executable(ccpp src/main.cpp)


add_library(timeops STATIC) 
target_sources(timeops PRIVATE src/time_op.c)

add_library(vector STATIC)
target_sources(vector PRIVATE 01-DataType/vector.cpp)

add_library(str STATIC)
target_sources(str PRIVATE 01-DataType/string.cpp)

add_library(oop STATIC)
target_sources(oop PRIVATE ${OOP})

add_library(mem STATIC)
target_sources(mem PRIVATE point/newdelete.cpp)

add_library(co STATIC)
target_sources(co PRIVATE 06-coroutine/coroutine.cpp)

target_link_libraries(ccpp PRIVATE 
  oop
  timeops 
  vector 
  str 
  mem
  co
)


