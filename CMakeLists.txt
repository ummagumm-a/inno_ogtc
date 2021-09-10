cmake_minimum_required(VERSION 3.10)

project(inno_ogtc)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(srcFiles main.cpp src/Tree.cpp src/BaseHolder.cpp)

include_directories(include)

add_executable(${PROJECT_NAME} ${srcFiles})
