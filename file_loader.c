//
// Created by thomas on 10/20/25.
//

#include "file_loader.h"

void list_export(t_adj_list graph){
    FILE *export_file = fopen("list.txt", "w");
    if (export_file != NULL){
        fprintf(export_file, "---\nconfig:\n    layout: elk\n   theme: neo\n    look: neo\n---\n\nflowchart LR\n");
        for (int i =0; i < graph.size; i++){
            fprintf(export_file,"%c((%d))\n",'a'+i,i+1);
        }
    }
    fclose(export_file);
}



