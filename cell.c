//
// Created by thomas on 10/20/25.
//

#include "cell.h"

#include <stdlib.h>

t_cell * create_cell(const int index_to, const float value) {
    t_cell * cell = (t_cell *) malloc(sizeof(t_cell));
    cell->value = value;
    cell->index_to = index_to;
    return cell;
}

void free_cell(t_cell * cell) {
    free(cell);
}

void print_cell(const t_cell * cell) {
    printf("--> [%d|%f|@%p]", cell->index_to, cell->value, cell);
}
