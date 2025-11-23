//
// Created by thomas on 10/20/25.
//

#ifndef SSDP_2_PROJET_LIST_H
#define SSDP_2_PROJET_LIST_H

#include "cell.h"
#include <stdio.h>

struct s_list {
    t_cell * head;
} typedef t_list;

/**
 * @brief Creates a new empty linked list.
 *
 * @return t_list* Pointer to the newly created list.
 */
t_list * create_empty_list();

/**
 * @brief Frees the memory allocated for a linked list and all its cells.
 *
 * @param list Pointer to the list to free.
 */
void free_list(t_list *);

/**
 * @brief Prints the contents of a linked list to the console.
 *
 * @param list Pointer to the list to print.
 */
void print_list(const t_list *);

/**
 * @brief Adds a new cell to the end of a linked list.
 *
 * @param list Pointer to the list.
 * @param index The destination vertex index for the edge.
 * @param value The weight/probability of the edge.
 */
void add_cell_to_list(t_list *,int , float);

#endif //SSDP_2_PROJET_LIST_H