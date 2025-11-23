//
// Created by matth on 20/11/2025.
//

#ifndef SSDP_2_PROJET_MATRIX_H
#define SSDP_2_PROJET_MATRIX_H

#include "adjacency_list.h"
#include "partition.h"
#include <stdio.h>
#include <stdlib.h>

#define EPSILON_CONVERGENCE 0.0001
#define MAX_ITERATIONS 1000

struct s_matrix{
    int size;
    float** values;
}typedef t_matrix;

t_matrix create_empty_matrix(int);
t_matrix create_adj_matrix(t_adj_list);
void free_matrix(t_matrix*);
t_matrix copy_matrix(t_matrix);
void mult_matrix(t_matrix, t_matrix);
float diff_matrix(t_matrix, t_matrix);
void print_matrix(t_matrix);

/**
 * @brief Extracts a submatrix corresponding to a specific
 * component of a graph partition.
 *
 * @param matrix The original adjacency matrix of the graph.
 * @param part The partition of the graph into strongly
 * connected components.
 * @param compo_index The index of the component to extract.
 * @return t_matrix The submatrix corresponding to the
 * specified component.
 */
t_matrix subMatrix(t_matrix matrix, t_partition part, int compo_index);

/**
 * @brief Calculates the stationary distribution of a matrix by computing
 * successive powers until convergence.
 *
 * @param matrix The transition matrix.
 * @param epsilon The convergence threshold.
 * @param max_iter Maximum number of iterations.
 * @return t_matrix The converged matrix (stationary distribution in each row).
 */
t_matrix stationary_distribution(t_matrix matrix);

#endif //SSDP_2_PROJET_MATRIX_H