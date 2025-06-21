cmake_minimum_required(VERSION 4.0)

project( Cube2Frame )

find_package( OpenCV REQUIRED)

include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable( cube cube.cpp )

target_link_libraries( cube ${OpenCV_LIBS} )