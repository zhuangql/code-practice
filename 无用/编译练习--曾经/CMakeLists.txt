cmake_minimum_required(VERSION 3.0.0)
project(demo VERSION 0.1.0)

find_package(Boost COMPONENTS program_options )
#find_package(Boost 1.67 REQUIRED COMPONENTS program_options unit_test_framework)
#include_directories(/home/xeniro/下载/boost_1_75_0)
#link_directories(/home/xeniro/下载/boost_1_75_0/stage/lib)
#include_directories(sub)
add_executable(demo main.cpp student.cpp)
target_link_libraries( demo ${Boost_LIBRARIES} )#库文件没有后缀的名字

