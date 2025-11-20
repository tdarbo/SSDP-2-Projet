//
// Created by thomas on 11/10/25.
//

#ifndef SSDP_2_PROJET_VERTEX_H
#define SSDP_2_PROJET_VERTEX_H

#include "adjacency_list.h"
#include "partition.h"

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

struct s_class_association_list
{
    int *id;
    int size;
} typedef t_class_association_list;

t_vertex_list create_vertex_list(t_adj_list);
void suppress_vertex_list(t_vertex_list);

t_class_association_list create_class_association_list();
void delete_association_list(t_class_association_list);
t_class_association_list create_fill_association_list(t_partition);

#endif //SSDP_2_PROJET_VERTEX_H