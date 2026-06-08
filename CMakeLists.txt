cmake_minimum_required(VERSION 3.10.11)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

# 项目描述文件
project(ccpp VERSION 0.1.0 LANGUAGES C CXX)

include_directories(include)

aux_source_directory(src/*.cpp SOURCES)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/libs)

# 指定内部子目录中还存在 CMakeLists.txt 的文件夹
# 行为：进入子目录,执行子目录CMakeLists.txt,再回到当前文件
# add_subdirectory(src)

aux_source_directory(03-oop/ OOP)
aux_source_directory(point/ POINT)
aux_source_directory(01-datatype/ TYPESOURCE)
aux_source_directory(06-coroutine/ COROUTINE)

add_executable(ccpp src/main.cpp)

add_library(timeops STATIC) 
target_sources(timeops PRIVATE 10-time/time_op.c)

add_library(oop STATIC)
target_sources(oop PRIVATE ${OOP})

add_library(point STATIC)
target_sources(point PRIVATE ${POINT})

add_library(dtype STATIC)
target_sources(dtype PRIVATE ${TYPESOURCE})

add_library(coroutine STATIC)
target_sources(coroutine PRIVATE ${COROUTINE})


target_link_libraries(ccpp PRIVATE 
  oop
  timeops 
  dtype
  point
  coroutine
)


