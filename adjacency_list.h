//
// Created by thomas on 10/20/25.
//

#ifndef SSDP_2_PROJET_ADJACENCYLIST_H
#define SSDP_2_PROJET_ADJACENCYLIST_H

#include "list.h"

struct s_adjacency_list {
    t_list ** inner_list;
    int size;
} typedef t_adj_list;

/**
 * @brief Creates an empty adjacency list with the specified number of vertices.
 *
 * @param size The number of vertices in the graph.
 * @return t_adj_list* Pointer to the newly created adjacency list.
 */
t_adj_list * create_empty_adj_list(int);

/**
 * @brief Frees the memory allocated for an adjacency list.
 *
 * @param adj_list Pointer to the adjacency list to free.
 */
void free_adj_list(t_adj_list *);

/**
 * @brief Prints the contents of an adjacency list to the console.
 *
 * @param adj_list Pointer to the adjacency list to print.
 */
void print_adj_list(const t_adj_list *);

/**
 * @brief Adds an edge to the adjacency list.
 *
 * @param adj_list Pointer to the adjacency list.
 * @param list_index The index of the source vertex (0-based).
 * @param cell_index_to The index of the destination vertex (1-based).
 * @param cell_value The weight/probability of the edge.
 */
void add_cell_to_adj_list(t_adj_list *, int, int, float);

/**
 * @brief Validates if the adjacency list represents a Markov chain.
 *
 * Checks if the sum of outgoing edge weights for each vertex equals 1.0
 * (within an approximation range).
 *
 * @param adj_list Pointer to the adjacency list to validate.
 * @return int 1 if the graph is a valid Markov chain, 0 otherwise.
 */
int validate_adj_list(t_adj_list *);

/**
 * @brief Converts a numeric vertex ID to an alphabetic identifier (A, B, C, ..., AA, AB, ...).
 *
 * @param num The numeric vertex ID (1-based).
 * @return char* The alphabetic identifier (static buffer).
 */
char * getId(int num);

/**
 * @brief Generates a Mermaid flowchart file from an adjacency list.
 *
 * Creates a Mermaid diagram representation of the graph with vertices and weighted edges.
 *
 * @param adj_list Pointer to the adjacency list.
 * @param filename The name of the output file to create.
 */
void generate_mermaid_file(const t_adj_list * adj_list, const char * filename);


#endif //SSDP_2_PROJET_ADJACENCYLIST_H