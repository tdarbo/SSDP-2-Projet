//
// Created by matth on 20/11/2025.
//

#ifndef SSDP_2_PROJET_MATRIX_H
#define SSDP_2_PROJET_MATRIX_H

#include "adjacency_list.h"
#include "partition.h"
#include <stdio.h>
#include <stdlib.h>

#define EPSILON_CONVERGENCE 0.01
#define MAX_ITERATIONS 1000

struct s_matrix{
    int size;
    float** values;
}typedef t_matrix;

/**
 * @brief Creates an empty square matrix of the specified size.
 *
 * @param size The dimension of the square matrix to create.
 * @return t_matrix An empty matrix with all values initialized to 0.
 */
t_matrix create_empty_matrix(int);

/**
 * @brief Creates an adjacency matrix from an adjacency list representation.
 *
 * @param list The adjacency list to convert.
 * @return t_matrix The corresponding adjacency matrix.
 */
t_matrix create_adj_matrix(t_adj_list);

/**
 * @brief Frees the memory allocated for a matrix.
 *
 * @param matrix Pointer to the matrix to free.
 */
void free_matrix(t_matrix*);

/**
 * @brief Creates a deep copy of a matrix.
 *
 * @param matrix The matrix to copy.
 * @return t_matrix A new matrix that is a copy of the input matrix.
 */
t_matrix copy_matrix(t_matrix);

/**
 * @brief Multiplies two matrices and stores the result in the first matrix.
 *
 * @param matrix_a The first matrix (will contain the result).
 * @param matrix_b The second matrix.
 */
void mult_matrix(t_matrix, t_matrix);

/**
 * @brief Calculates the sum of absolute differences between two matrices.
 *
 * @param matrix_a The first matrix.
 * @param matrix_b The second matrix.
 * @return float The sum of absolute differences between corresponding elements.
 */
float diff_matrix(t_matrix, t_matrix);

/**
 * @brief Prints a matrix to the console in a formatted manner.
 *
 * @param matrix The matrix to print.
 */
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
 * @return t_matrix The converged matrix (stationary distribution in each row).
 */
t_matrix stationary_distribution(t_matrix matrix);

#endif //SSDP_2_PROJET_MATRIX_H