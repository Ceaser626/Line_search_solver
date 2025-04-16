cmake_minimum_required(VERSION 3.30)
project(line_search VERSION 1.0 LANGUAGES CXX)

#set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#include_directories("D:\\Programming Pack\\vcpkg\\installed\\x64-mingw-dynamic\\include\\Eigen3")
set(CMAKE_PREFIX_PATH "D:\\Programming Pack\\vcpkg\\installed\\x64-mingw-dynamic")
find_package(Eigen3 REQUIRED)

# 先添加子目录和库
add_subdirectory(src/ls_solver)

# 再添加 main 并链接库
add_executable(main src/ls_solver/main.cpp)
target_link_libraries(main PRIVATE lssolverstatic Eigen3::Eigen)
