//
// Created by thomas on 10/20/25.
//

#ifndef SSDP_2_PROJET_LIST_H
#define SSDP_2_PROJET_LIST_H

#include "Cell.h"

struct s_list {
    t_cell * head;
} typedef t_list;

t_list * create_empty_list();
void free_list(t_list *);

#endif //SSDP_2_PROJET_LIST_H