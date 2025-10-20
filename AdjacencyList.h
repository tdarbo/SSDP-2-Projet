//
// Created by thomas on 10/20/25.
//

#ifndef SSDP_2_PROJET_ADJACENCYLIST_H
#define SSDP_2_PROJET_ADJACENCYLIST_H

#include "List.h"

struct s_adjacency_list {
    t_list * head;
    int size;
} typedef t_adj_list;

t_adj_list * create_empty_adj_list(int);

#endif //SSDP_2_PROJET_ADJACENCYLIST_H