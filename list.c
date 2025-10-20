//
// Created by thomas on 10/20/25.
//

#include "list.h"

#include <stdlib.h>


t_list * create_empty_list(const int size) {
    t_list * list = (t_list *) malloc(sizeof(t_list));
    for (int i = 0; i < size; ++i) {

    }
    return list;
}

void free_list(t_list * list) {
    t_cell * cell = list->head;

    while (cell != NULL) {
        t_cell * temp = cell;
        cell = cell->next;
        free_cell(temp);
    }

    free(list);
}

void print_list(const t_list * list) {
     const t_cell * cell = list->head;
    printf("[HEAD @%p] ",cell);
    while (cell != NULL) {
        print_cell(cell);
    }
    printf("\n");
}


