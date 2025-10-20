//
// Created by thomas on 10/20/25.
//

#include "adjacency_list.h"
#include "list.h"
#include <stdlib.h>
#include <stdio.h>

t_adj_list * create_empty_adj_list(const int size) {
    t_adj_list * new_adj_list = (t_adj_list *) malloc(sizeof(t_adj_list));
    t_list ** inner_list = (t_list **) malloc(sizeof(t_list*)*size);

    new_adj_list->size = size;
    new_adj_list->inner_list = inner_list;

    for (int i = 0; i < size; ++i) {
        inner_list[i] = create_empty_list();
    }

    return new_adj_list;
}

void free_adj_list(t_adj_list * adj_list) {

    t_list ** a_list = adj_list->inner_list;
    const int size = adj_list->size;

    for (int i = 0; i < size; ++i) {
        free(a_list[i]);
    }

    free(adj_list);
}

void print_adj_list(const t_adj_list * adj_list) {

    t_list ** a_list = adj_list->inner_list;
    const int size = adj_list->size;

    for (int i = 0; i < size; ++i) {
        printf("List %d : ",i+1);
        print_list(a_list[i]);
    }


}


void add_cell_to_adj_list(t_adj_list * adj_list, const int list_index, const int cell_index_to, const float cell_value) {
    if (adj_list == NULL) return;
    if (adj_list->inner_list == NULL) return;
    if (list_index < 0 || list_index >= adj_list->size) return;

    add_cell_to_list(adj_list->inner_list[list_index], cell_index_to, cell_value);


}