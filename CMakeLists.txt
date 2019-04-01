cmake_minimum_required(VERSION 3.13)
project(Shake)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Shake
        constant.h
        main.cpp
        pixel.cpp
        pixel.h
        Shake.cpp
        Shake.h Game.cpp Game.h Graphic.cpp Graphic.h Ncurses.cpp Ncurses.h)
