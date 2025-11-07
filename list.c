//
// Created by thomas on 10/20/25.
//

#include "list.h"

#include <stdlib.h>


t_list * create_empty_list() {
    t_list * list = (t_list *) malloc(sizeof(t_list));
    list->head = NULL;
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

void add_cell_to_list(t_list * list, int index, float value) {
    if (list == NULL) return;
    t_cell * new_cell = create_cell(index, value);
    if (list->head == NULL) {
        list->head = new_cell;
        return;
    }
    t_cell * temp = list->head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_cell;
}


void print_list(const t_list * list) {
    const t_cell * cell = list->head;
    printf("[HEAD @%p] ",cell);
    while (cell != NULL) {
        print_cell(cell);
        cell = cell->next;
    }
    printf("\n");
}


