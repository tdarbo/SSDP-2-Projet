//
// Created by thomas on 10/20/25.
//

#ifndef SSDP_2_PROJET_CELL_H
#define SSDP_2_PROJET_CELL_H

struct s_cell {
    int value;
    struct s_cell *next;
} typedef t_cell;

t_cell * create_cell(int);
void free_cell(t_cell *);

#endif //SSDP_2_PROJET_CELL_H