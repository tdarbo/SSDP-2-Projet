//
// Created by thomas on 10/20/25.
//

#include "cell.h"

#include <stdlib.h>

t_cell * create_cell(const int index_to, const float value) {
    t_cell * cell = (t_cell *) malloc(sizeof(t_cell));
    cell->value = value;
    cell->index_to = index_to;
    cell->next = NULL;
    return cell;
}

void free_cell(t_cell * cell) {
    if (cell == NULL) {printf("Erreur: cellule invalide\n"); return;}
    free(cell);
}

void print_cell(const t_cell * cell) {
    if (cell == NULL) {printf("Erreur: cellule invalide\n"); return;}
    if (cell->next == NULL) {
        printf("--> [%d|%.2f|@null]", cell->index_to, cell->value);
    } else {
        printf("--> [%d|%.2f|@%p]", cell->index_to, cell->value, cell->next);
    }

}
