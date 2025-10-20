//
// Created by thomas on 10/20/25.
//

#ifndef SSDP_2_PROJET_LIST_H
#define SSDP_2_PROJET_LIST_H

#include "cell.h"
#include <stdio.h>

struct s_list {
    int size;
    t_cell * head;
} typedef t_list;

t_list * create_empty_list(const int size);
void free_list(t_list *);
void print_list(const t_list *);

#endif //SSDP_2_PROJET_LIST_H