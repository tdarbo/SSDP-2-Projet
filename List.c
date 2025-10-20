//
// Created by thomas on 10/20/25.
//

#include "List.h"

#include <stdlib.h>


t_list * create_empty_list() {
    t_list * list = (t_list *) malloc(sizeof(t_list));
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

void print_list(t_list * list) {
}


