cmake_minimum_required(VERSION 3.5)
project(c)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    ctx.h
    ctx_i.c
    IO.h
    IO_i.c
    LIGHT.h
    LIGHT_i.c
    LIGHTS.h
    LIGHTS_i.c
    M0.h
    M0_i.c
    main.c)

add_executable(c ${SOURCE_FILES})