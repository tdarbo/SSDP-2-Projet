//
// Created by thomas on 23/11/2025.
//

#ifndef LINKS_H
#define LINKS_H

#include "partition.h"
#include "adjacency_list.h"

typedef struct s_link {
    int source;
    int target;
} t_link;

typedef struct s_link_list {
    t_link* links;
    int size;
    int capacity;
} t_link_list;

t_link_list create_link_list(int capacity);
void free_link_list(t_link_list* list);

int* create_vertex_to_class_map(t_partition partition, int num_vertices);

int link_exists(t_link_list list, int src, int tgt);
void add_link(t_link_list* list, int src, int tgt);

t_link_list find_inter_class_links(t_adj_list* graph, t_partition partition);
void print_links(t_link_list list);

void print_graph_characteristics(t_partition, t_link_list);

#endif //LINKS_H
