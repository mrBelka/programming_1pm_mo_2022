cmake_minimum_required(VERSION 3.8)
project( DisplayImage )


set(OpenCV_DIR "C:\\Users\\Misha\\Downloads\\build\\install")

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
message(${OpenCV_INCLUDE_DIRS})
link_directories(${OpenCV_LIB_DIR})

add_executable( DisplayImage main.cpp )

target_link_libraries(DisplayImage ${OpenCV_LIBS})