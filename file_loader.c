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
        add_cell_to_adj_list(adj_list, node-1, index_to, weight);
    }
    fclose(adj_file);
    return adj_list;
}

void list_export(t_adj_list graph){
    FILE *export_file = fopen("D:/0_Code/C++/SSDP-2-Projet/export/list.txt", "w");
    if (export_file != NULL){
        fprintf(export_file, "---\nconfig:\n    layout: elk\n   theme: neo\n    look: neo\n---\n\nflowchart LR\n");
        for (int i =0; i < graph.size; i++){
            fprintf(export_file,"%c((%d))\n",'A'+i,i+1);
        }
        fprintf(export_file,"\n");
        for (int i =0; i < graph.size; i++){
            t_cell * cell = graph.inner_list[i]->head;
            while (cell != NULL) {
                fprintf(export_file,"%c -->|%.2f|%c\n",'A'+i,cell->value,'A'+cell->index_to-1);
                cell = cell->next;
            }
        }
    }
    fclose(export_file);
}



