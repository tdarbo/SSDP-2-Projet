//
// Created by matth on 20/11/2025.
//

#include "matrix.h"

t_matrix create_empty_matrix(int size)
{
    t_matrix new_matrix;
    new_matrix.col = malloc(sizeof(float*)*size);
    for (int i=0; i<size; i++)
    {
        new_matrix.col[i] = malloc(sizeof(float)*size);
    }
}

t_matrix create_adj_matrix(t_adj_list list)
{

}

void free_matrix(t_matrix matrix)
{
    free();
}

t_matrix copie_matrix(t_matrix matrix)
{

}

t_matrix mult_matrix(t_matrix, t_matrix)
{

}

int diff_matrix(t_matrix, t_matrix)
{

}