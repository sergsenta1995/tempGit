cmake_minimum_required(VERSION 3.5)
project(tempGit)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(OpenCV REQUIRED)
find_package(GTest REQUIRED)

set(SOURCE_FILES main.cpp)
add_executable(tempGit ${SOURCE_FILES})

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${GTEST_INCLUDE_DIRS})

target_link_libraries(tempGit ${OpenCV_LIBS})
target_link_libraries(tempGit ${GTEST_LIBRARIES} pthread)