cmake_minimum_required(VERSION 3.0.0)
project(demo VERSION 0.1.0)

find_package(Boost COMPONENTS program_options )
#find_package(Boost 1.67 REQUIRED COMPONENTS program_options unit_test_framework)
#include_directories(/home/xeniro/下载/boost_1_75_0)
#link_directories(/home/xeniro/下载/boost_1_75_0/stage/lib)
#include_directories(sub)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/bin) 
add_executable(unit_test test.cpp)
target_link_libraries( unit_test ${Boost_LIBRARIES} )#库文件没有后缀的名字

