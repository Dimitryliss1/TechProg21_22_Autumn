cmake_minimum_required(VERSION 3.15)
project(LR1)

set(CMAKE_CXX_STANDARD 20)

add_executable(LR1 main.cpp Base.cpp Base.h Hero.cpp Hero.h CourtCase.cpp CourtCase.h Villain.cpp Villain.h Monster.cpp Monster.h useful.h useful.cpp Keeper.cpp Keeper.h)