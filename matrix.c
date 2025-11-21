//
// Created by matth on 20/11/2025.
//

#include "matrix.h"

t_matrix create_empty_matrix(int size){
    t_matrix new_matrix;
    new_matrix.size = size;
    if (new_matrix.size == 0) {
        new_matrix.values = NULL;
        return new_matrix;
    }
    new_matrix.values = calloc(size,sizeof(float*));
    for (int i=0; i<size; i++){
        new_matrix.values[i] = calloc(size,sizeof(float));
    }
    return new_matrix;
}

t_matrix create_adj_matrix(t_adj_list list){
    t_matrix new_matrix = create_empty_matrix(list.size);
    if (new_matrix.values == NULL){
        return new_matrix;
    }
    for (int i=0; i<list.size; i++){
        t_cell* cur = list.inner_list[i]->head;
        while (cur != NULL){
            new_matrix.values[i][cur->index_to-1] = cur->value;
            cur = cur->next;
        }
    }
    return new_matrix;
}

void free_matrix(t_matrix matrix){
    for(int i = 0; i < matrix.size; i++){
        free(matrix.values[i]);
    }
    free(matrix.values);
}

t_matrix copy_matrix(t_matrix matrix){
    t_matrix new_matrix;
    new_matrix.size = matrix.size;
    if (new_matrix.size == 0){
        new_matrix.values = NULL;
        return new_matrix;
    }
    new_matrix.values = malloc(matrix.size*sizeof(float*));
    for (int i=0; i<matrix.size; i++){
        new_matrix.values[i] = malloc(matrix.size*sizeof(float));
        for (int j=0; j<matrix.size; j++)
        {
            new_matrix.values[i][j] = matrix.values[i][j];
        }
    }
    return new_matrix;
}

t_matrix mult_matrix(t_matrix matrix_a, t_matrix matrix_b){
    int size = matrix_a.size;
    float temp;
    for (int i=0; i<size; i++){
        for (int j=0; j<size; j++){
            temp = 0;
            for (int k=0; k<size; k++){
                temp += matrix_a.values[k][j] * matrix_b.values[i][k];
            }
            matrix_a.values[i][j] = temp;
        }
    }
    return matrix_a;
}

float diff_matrix(t_matrix matrix_a, t_matrix matrix_b){
    float val = 0, temp;
    int size = matrix_a.size;
    for (int i=0; i<size; i++){
        for (int j=0; j<size; j++){
            temp = matrix_a.values[i][j] - matrix_b.values[i][j];
            if (temp>=0) val += temp;
            else val -= temp;
        }
    }
    return val;
}

void print_matrix(t_matrix matrix){
    printf("print matrix :\n");
    for (int i=0; i<matrix.size; i++){
        for (int j=0; j<matrix.size-1; j++){
            printf("%.2f | ", matrix.values[i][j]);
        }
        printf("%.2f\n" ,matrix.values[i][matrix.size-1]);
    }
}