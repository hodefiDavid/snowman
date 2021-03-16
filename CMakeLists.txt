cmake_minimum_required(VERSION 3.17)
project(snowmen)

set(CMAKE_CXX_STANDARD 20)

#add_executable(snowmen snowman.hpp )
add_executable(Demo Demo.cpp snowman.hpp snowman.cpp )
add_executable(Test Test.cpp TestCounter.cpp doctest.h snowman.hpp snowman.cpp )
add_executable(m main.cpp snowman.hpp snowman.cpp)