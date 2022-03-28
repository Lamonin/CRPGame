cmake_minimum_required(VERSION 3.21)
project(crpgame)

set(CMAKE_CXX_STANDARD 20)

add_executable(crpgame main.cpp engine.cpp engine.h crpgdata.cpp crpgdata.h doublelist.h)
