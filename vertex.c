//
// Created by thomas on 11/10/25.
//

#include "vertex.h"

#include <stdlib.h>

t_vertex_list create_vertex_list(t_adj_list adj_list){
    t_vertex_list vertex_list;
    // Allocate an array of t_vertex
    t_vertex* list = malloc(sizeof(t_vertex) * adj_list.size);
    if (list == NULL) {
        vertex_list.vertex = NULL;
        return vertex_list;
    }
    // Initialize each vertex in-place
    for(int i = 0; i < adj_list.size; i++){
        list[i].id = i + 1;
        list[i].accces_number = -1;
        list[i].number = -1;
        list[i].inStack = 0;
    }
    vertex_list.vertex = list;
    return vertex_list;
}
void suppress_vertex_list(t_vertex_list vertex_list){
    free(vertex_list.vertex);
}