cmake_minimum_required(VERSION 3.10.11)

# 项目描述文件
project(ccpp VERSION 0.1.0 LANGUAGES C CXX)

include_directories(include)

# aux_source_directory(src/*.cpp SOURCES)


add_executable(ccpp src/main.cpp)


add_library(shape STATIC)
target_sources(shape PRIVATE 03-oop/Shape.cpp)

add_library(complex STATIC)
target_sources(complex PRIVATE 03-oop/Complex.cpp)

add_library(timeops STATIC) 
target_sources(timeops PRIVATE src/time_op.c)

target_link_libraries(ccpp PRIVATE shape complex timeops)


