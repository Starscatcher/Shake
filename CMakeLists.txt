cmake_minimum_required(VERSION 3.13)
project(Shake)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Shake
        main.cpp
        Pixel.cpp
        Pixel.h
        Shake.cpp
        Shake.h Game.cpp Game.h Graphic.cpp Graphic.h Ncurses.cpp Ncurses.h GameConstants.h)
