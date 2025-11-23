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

t_class_association_list create_class_association_list() {
    t_class_association_list association_list;
    association_list.size = 0;
    int* l = (int*) malloc(sizeof(int) * SIZE);
    if (l == NULL) {
        association_list.id = NULL;
        return association_list;
    }
    association_list.id = l;
    return association_list;
}

void delete_association_list(t_class_association_list association_list) {
    free(association_list.id);
}


t_class_association_list create_fill_association_list(const t_partition partition) {
    const t_class_association_list association_list = create_class_association_list();
    for (int i = 0; i < partition.size; i++) {
        const t_class c = partition.classes[i];
        for (int j = 0; j < c.size; j++) {
            const int vertex_id = c.index[j];
            association_list.id[vertex_id] = c.name;
        }
    }
    return association_list;
}

void suppress_vertex_list(t_vertex_list vertex_list){
    free(vertex_list.vertex);
}