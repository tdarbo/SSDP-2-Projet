//
// Created by matth on 20/11/2025.
//

#include "matrix.h"

t_matrix create_empty_matrix(int size)
{
    t_matrix new_matrix;
    new_matrix.size = size;
    new_matrix.col = calloc(size,sizeof(float*));
    for (int i=0; i<size; i++)
    {
        new_matrix.col[i] = calloc(size,sizeof(float));
    }
    return new_matrix;
}

t_matrix create_adj_matrix(t_adj_list list)
{

}

void free_matrix(t_matrix matrix)
{
    for(int i = 0; i < matrix.size; i++){
        free(matrix.values[i]);
    }
    free(matrix.values);
}

t_matrix copy_matrix(t_matrix matrix)
{
    t_matrix new_matrix;
    new_matrix.size = matrix.size;
    new_matrix.values = malloc(matrix.size*sizeof(float*));
    for (int i=0; i<matrix.size; i++)
    {
        new_matrix.values[i] = malloc(matrix.size*sizeof(float));
        for (int j=0; j<matrix.size; j++)
        {
            new_matrix.values[i][j] = matrix.values[i][j];
        }
    }
    return new_matrix;
}

t_matrix mult_matrix(t_matrix, t_matrix)
{

}

int diff_matrix(t_matrix matrix_a, t_matrix matrix_b)
{
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