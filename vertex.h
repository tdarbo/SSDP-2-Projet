//
// Created by thomas on 11/10/25.
//

#ifndef SSDP_2_PROJET_VERTEX_H
#define SSDP_2_PROJET_VERTEX_H

#include "adjacency_list.h"

#define SIZE 100

struct s_vertex {

    int id;
    int number;
    int accces_number;
    int inStack;

} typedef t_vertex;

struct s_vertex_list {
    t_vertex* vertex;
} typedef t_vertex_list;

t_vertex_list create_vertex_list(t_adj_list);

#endif //SSDP_2_PROJET_VERTEX_H