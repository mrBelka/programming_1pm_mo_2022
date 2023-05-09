cmake_minimum_required(VERSION 3.8)
project(opencv_example)

include_directories("C:\\Users\\Misha\\Downloads\\opencv\\build\\include")
link_directories("C:\\Users\\Misha\\Downloads\\opencv\\build\\x64\\vc15\\lib")

add_executable(opencv_example main.cpp)

target_link_libraries(opencv_example debug opencv_world455d.lib)
target_link_libraries(opencv_example optimized opencv_world455.lib)