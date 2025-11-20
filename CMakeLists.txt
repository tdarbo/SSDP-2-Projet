cmake_minimum_required(VERSION 3.31.6)
project(SSDP_2_Projet C)

set(CMAKE_C_STANDARD 11)

add_executable(SSDP_2_Projet main.c
        file_loader.c
        file_loader.h
        cell.c
        cell.h
        list.c
        list.h
        adjacency_list.c
        adjacency_list.h
        vertex.c
        vertex.h
        partition.c
        partition.h
        class.c
        class.h
        tarjan.c
        tarjan.h
        link.c
        link.h
)
