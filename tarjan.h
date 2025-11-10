//
// Created by thomas on 11/10/25.
//

#ifndef SSDP_2_PROJET_TARJAN_H
#define SSDP_2_PROJET_TARJAN_H

#include "adjacency_list.h"
#include "partition.h"
#include "vertex.h"
#include "class.h"


#define BOOL int
#define TRUE 1
#define FALSE 0

struct s_pile{
    int* pile;
    int size;
}typedef t_pile;

t_pile create_pile();
void destroy_pile(t_pile*);
int pop(t_pile*);
void push(t_pile*, int);
void delete_pile(t_pile*);

void parcours(t_vertex, int*, t_pile*, t_partition*, t_adj_list* graph,t_vertex_list*);
t_partition tarjan(t_adj_list*);
int min(int,int);


#endif //SSDP_2_PROJET_TARJAN_H
