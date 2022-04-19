cmake_minimum_required(VERSION 3.21)
project(crpgame)

set(CMAKE_CXX_STANDARD 20)

add_executable(crpgame main.cpp engine.cpp engine.h crpgdata.cpp crpgdata.h bilist.h game/races.cpp game/races.h game/hero_types.cpp game/hero_types.h game/heroes.cpp game/heroes.h game/weapons.cpp game/weapons.h game/armors.cpp game/armors.h)
