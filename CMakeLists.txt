cmake_minimum_required(VERSION 4.0)

project(Cube2Frame)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR}/include)

add_executable(cube2frame 
               src/main.cpp
               include/color_map.cpp
               include/cube_mosaic.cpp)
 
target_link_libraries(cube2frame ${OpenCV_LIBS})