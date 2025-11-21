//
// Created by matth on 20/11/2025.
//

#ifndef SSDP_2_PROJET_MATRIX_H
#define SSDP_2_PROJET_MATRIX_H

#include "adjacency_list.h"
#include <stdio.h>
#include <stdlib.h>

struct s_matrix{
    int size;
    float** values;
}typedef t_matrix;

t_matrix create_empty_matrix(int);
t_matrix create_adj_matrix(t_adj_list);
void free_matrix(t_matrix);
t_matrix copy_matrix(t_matrix);
t_matrix mult_matrix(t_matrix, t_matrix);
float diff_matrix(t_matrix, t_matrix);
void print_matrix(t_matrix);

#endif //SSDP_2_PROJET_MATRIX_H