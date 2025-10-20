//
// Created by thomas on 10/20/25.
//

#include "adjacency_list.h"

#include <stdlib.h>
#include <stdio.h>

t_adj_list * create_empty_adj_list(const int size) {
    t_adj_list * new_adj_list = (t_adj_list *) malloc(sizeof(t_adj_list));
    t_list ** inner_list = (t_list **) malloc(sizeof(t_list*)*size);

    new_adj_list->size = size;
    new_adj_list->inner_list = inner_list;

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
