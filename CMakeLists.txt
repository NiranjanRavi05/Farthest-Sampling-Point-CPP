﻿# CMakeList.txt : CMake project for FSA, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("FSA")

# Add source to this project's executable.
add_executable (FSA "fps.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET FSA PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
