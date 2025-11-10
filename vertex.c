//
// Created by thomas on 11/10/25.
//

#include "vertex.h"

#include <stdlib.h>

t_vertex_list create_vertex_list(t_adj_list adj_list){
    t_vertex_list vertex_list;
    t_vertex* list = malloc(sizeof(struct s_vertex_list)*adj_list.size);
    for(int i = 0; i < adj_list.size; i++){
        t_vertex vertex = list[i];
        vertex.id = i+1;
        vertex.accces_number = -1;
        vertex.number = -1;
        vertex.inStack = 0;
    }
    vertex_list.vertex = list;
    return vertex_list;
}
void suppress_vertex_list(t_vertex_list vertex_list){
    free(vertex_list.vertex);
}