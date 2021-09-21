cmake_minimum_required(VERSION 3.17)
project(vegetables)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_PREFIX_PATH "C:\\Qt\\5.15.2\\mingw81_64\\lib\\cmake")
find_package(Qt5Widgets REQUIRED)

add_executable(vegetables main.cpp Object.cpp Object.h Repository.cpp Repository.h Service.cpp Service.h GUI.cpp GUI.h)

target_link_libraries(vegetables Qt5::Widgets)
