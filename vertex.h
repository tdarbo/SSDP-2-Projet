//
// Created by thomas on 11/10/25.
//

#ifndef SSDP_2_PROJET_VERTEX_H
#define SSDP_2_PROJET_VERTEX_H

#include "adjacency_list.h"
#include "partition.h"

#define SIZE 100

struct s_vertex {

    int id;
    int number;
    int accces_number;
    int inStack;

} typedef t_vertex;

struct s_vertex_list {
    t_vertex* vertex;
} typedef t_vertex_list;

struct s_class_association_list
{
    int *id;
    int size;
} typedef t_class_association_list;

/**
 * @brief Creates a list of vertices from an adjacency list.
 *
 * @param adj_list The adjacency list representing the graph.
 * @return t_vertex_list A list of vertices initialized for Tarjan's algorithm.
 */
t_vertex_list create_vertex_list(t_adj_list);

/**
 * @brief Frees the memory allocated for a vertex list.
 *
 * @param vertex_list The vertex list to free.
 */
void suppress_vertex_list(t_vertex_list);

/**
 * @brief Creates a new empty class association list.
 *
 * @return t_class_association_list A new association list initialized with empty content.
 */
t_class_association_list create_class_association_list();

/**
 * @brief Frees the memory allocated for a class association list.
 *
 * @param association_list The association list to delete.
 */
void delete_association_list(t_class_association_list);

/**
 * @brief Creates and fills a class association list from a partition.
 *
 * Maps each vertex ID to its corresponding class name.
 *
 * @param partition The partition containing the vertex-to-class mappings.
 * @return t_class_association_list An association list mapping vertices to classes.
 */
t_class_association_list create_fill_association_list(t_partition);

#endif //SSDP_2_PROJET_VERTEX_H