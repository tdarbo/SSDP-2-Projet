//
// Created by thomas on 10/20/25.
//

#include "file_loader.h"

t_adj_list* list_import(const char* file_name){
    FILE *adj_file = fopen(file_name, "r");
    int size , node, index_to;
    float weight;
    if (adj_file==NULL) {
        printf("Could not open file for reading");
        exit(EXIT_FAILURE);
    }
    if (fscanf(adj_file, "%d", &size) != 1) {
        printf("Could not read number of vertices");
        exit(EXIT_FAILURE);
    }
    t_adj_list* adj_list = create_empty_adj_list(size);
    while (fscanf(adj_file, "%d %d %f", &node, &index_to, &weight) == 3){
        printf("- %d %d %f \n", node, index_to, weight);
        add_cell_to_adj_list(adj_list, node-1, index_to, weight);
    }
    fclose(adj_file);
    return adj_list;
}


