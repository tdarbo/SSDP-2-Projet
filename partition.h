//
// Created by thomas on 11/10/25.
//

#ifndef SSDP_2_PROJET_PARTITION_H
#define SSDP_2_PROJET_PARTITION_H
#define PARTITION_MAX_SIZE 100

#include "class.h"

struct s_partition {

    t_class* classes;
    int size;

} typedef t_partition;

/**
 * @brief Creates a new empty partition.
 *
 * @return t_partition A new partition initialized with empty class list.
 */
t_partition create_partition();

/**
 * @brief Prints the contents of a partition to the console.
 *
 * @param p Pointer to the partition to print.
 */
void print_partition(t_partition*);

/**
 * @brief Frees the memory allocated for a partition and all its classes.
 *
 * @param p Pointer to the partition to delete.
 */
void delete_partition(t_partition*);

#endif //SSDP_2_PROJET_PARTITION_H