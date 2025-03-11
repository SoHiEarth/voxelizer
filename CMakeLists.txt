cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
project(Voxelizer VERSION 0.1 DESCRIPTION "Voxelizer - A 2D Game Library")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(Vulkan REQUIRED)

file(GLOB VOXELIZER_SRC "src/*.c" "src/**/*.c" "src/*.cc" "src/**/*.cc")

include_directories("include" "sdk")
link_libraries(SDL2::SDL2 SDL2_image::SDL2_image SDL2_ttf::SDL2_ttf Vulkan::Vulkan)
add_library(Voxelizer SHARED ${VOXELIZER_SRC})

# Test
add_library(Voxelizer_Lib SHARED IMPORTED)
add_executable(test "test/main.cc")
