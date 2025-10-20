//
// Created by thomas on 10/20/25.
//

#include "AdjacencyList.h"

#include <stdlib.h>

t_adj_list * create_empty_adj_list(const int size) {
    t_adj_list * new_adj_list = (t_adj_list *) malloc(sizeof(t_adj_list));
    t_list * inner_list = (t_list *) malloc(sizeof(t_list)*size);

    new_adj_list->size = size;
    new_adj_list->head = inner_list;

    return new_adj_list;
}
