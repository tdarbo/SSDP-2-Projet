//
// Created by thomas on 10/20/25.
//

#include "file_loader.h"

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
                fprintf(export_file,"%c -->|%.2f|%c\n",'A'+i,cell->value,'A'+cell->index_to);
                cell = cell->next;
            }
        }
    }
    fclose(export_file);
}



