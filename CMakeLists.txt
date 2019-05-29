cmake_minimum_required(VERSION 3.14)
project(SDL_MandelbrotSet)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})
include_directories(includes)

set(SOURCE_FILES src/main.cpp)

add_executable(SDL_MandelbrotSet main.cpp src/Screen.cpp includes/Screen.h src/Mandelbrot.cpp includes/Mandelbrot.h src/ZoomList.cpp includes/ZoomList.h includes/Zoom.h includes/RGB.h src/Fractal.cpp includes/Fractal.h src/RGB.cpp)
target_link_libraries(SDL_MandelbrotSet ${SDL2_LIBRARY})





