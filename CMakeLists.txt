cmake_minimum_required(VERSION 4.0)
project(SSDP_2_Projet C)

set(CMAKE_C_STANDARD 11)

add_executable(SSDP_2_Projet main.c
        FileLoader.c
        FileLoader.h
        Cell.c
        Cell.h
        List.c
        List.h
        AdjacencyList.c
        AdjacencyList.h)
