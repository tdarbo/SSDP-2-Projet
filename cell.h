//
// Created by thomas on 10/20/25.
//

#ifndef SSDP_2_PROJET_CELL_H
#define SSDP_2_PROJET_CELL_H

#include <stdio.h>

struct s_cell {
    float value;
    int index_to;
    struct s_cell *next;
} typedef t_cell;

/**
 * @brief Creates a new cell for a linked list with the specified edge information.
 *
 * @param index_to The destination vertex index.
 * @param value The weight/probability of the edge.
 * @return t_cell* Pointer to the newly created cell.
 */
t_cell * create_cell(int,float);

/**
 * @brief Frees the memory allocated for a cell.
 *
 * @param cell Pointer to the cell to free.
 */
void free_cell(t_cell *);

/**
 * @brief Prints the contents of a cell to the console.
 *
 * @param cell Pointer to the cell to print.
 */
void print_cell(const t_cell *);

#endif //SSDP_2_PROJET_CELL_H