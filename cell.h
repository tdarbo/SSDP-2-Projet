//
// Created by thomas on 10/20/25.
//

#ifndef SSDP_2_PROJET_CELL_H
#define SSDP_2_PROJET_CELL_H

#include <stdio.h>

struct s_cell {
    float value;
    int index_to;
    struct s_cell *next;
} typedef t_cell;

t_cell * create_cell(int,float);
void free_cell(t_cell *);
void print_cell(const t_cell *);

#endif //SSDP_2_PROJET_CELL_H