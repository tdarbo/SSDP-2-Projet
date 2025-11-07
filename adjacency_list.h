//
// Created by thomas on 10/20/25.
//

#ifndef SSDP_2_PROJET_ADJACENCYLIST_H
#define SSDP_2_PROJET_ADJACENCYLIST_H

#include "list.h"

struct s_adjacency_list {
    t_list ** inner_list;
    int size;
} typedef t_adj_list;

t_adj_list * create_empty_adj_list(int);
void free_adj_list(t_adj_list *);
void print_adj_list(const t_adj_list *);
void add_cell_to_adj_list(t_adj_list *, int, int, float);
int validate_adj_list(t_adj_list *);

#endif //SSDP_2_PROJET_ADJACENCYLIST_H