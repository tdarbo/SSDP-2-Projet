//
// Created by thomas on 11/10/25.
//

#ifndef SSDP_2_PROJET_TARJAN_H
#define SSDP_2_PROJET_TARJAN_H

#include "adjacency_list.h"
#include "partition.h"
#include "vertex.h"
struct s_pile{
    int* pile;
    int size;
}typedef t_pile;

t_pile create_pile();
void destroy_pile(t_pile*);
int pop(t_pile*);
void push(t_pile*, int);
void delete_pile(t_pile*);

#endif //SSDP_2_PROJET_TARJAN_H
