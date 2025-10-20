//
// Created by thomas on 10/20/25.
//

#include "Cell.h"

#include <stdlib.h>

t_cell * create_cell(const int value) {
    t_cell * cell = (t_cell *) malloc(sizeof(t_cell));
    return cell;
}

void free_cell(t_cell * cell) {
    free(cell);
}

void print_cell(const t_cell * cell) {
    printf("--> [%d|@%p]\n",cell->value,cell->next);
}
