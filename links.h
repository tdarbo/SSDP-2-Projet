//
// Created by thomas on 23/11/2025.
//

#ifndef LINKS_H
#define LINKS_H

#include "partition.h"
#include "adjacency_list.h"

typedef struct s_link {
    int source;
    int target;
} t_link;

typedef struct s_link_list {
    t_link* links;
    int size;
    int capacity;
} t_link_list;

/**
 * @brief Creates a new link list with the specified capacity.
 *
 * @param capacity The maximum number of links the list can hold.
 * @return t_link_list A new link list initialized with the given capacity.
 */
t_link_list create_link_list(int capacity);

/**
 * @brief Frees the memory allocated for a link list.
 *
 * @param list Pointer to the link list to free.
 */
void free_link_list(t_link_list* list);

/**
 * @brief Creates a mapping from vertex IDs to their class IDs in a partition.
 *
 * @param partition The partition containing the classes.
 * @param num_vertices The total number of vertices in the graph.
 * @return int* Array where index is vertex ID (0-based) and value is class ID.
 */
int* create_vertex_to_class_map(t_partition partition, int num_vertices);

/**
 * @brief Checks if a link between two classes already exists in the link list.
 *
 * @param list The link list to search.
 * @param src The source class ID.
 * @param tgt The target class ID.
 * @return int 1 if the link exists, 0 otherwise.
 */
int link_exists(t_link_list list, int src, int tgt);

/**
 * @brief Adds a new link between two classes to the link list.
 *
 * @param list Pointer to the link list.
 * @param src The source class ID.
 * @param tgt The target class ID.
 */
void add_link(t_link_list* list, int src, int tgt);

/**
 * @brief Finds all inter-class links in a graph partition.
 *
 * Identifies edges between different strongly connected components.
 *
 * @param graph Pointer to the adjacency list of the graph.
 * @param partition The partition of the graph into classes.
 * @return t_link_list A list of links between different classes.
 */
t_link_list find_inter_class_links(t_adj_list* graph, t_partition partition);

/**
 * @brief Prints all links in a link list to the console.
 *
 * @param list The link list to print.
 */
void print_links(t_link_list list);

/**
 * @brief Prints detailed characteristics of a partitioned graph.
 *
 * Analyzes and displays whether the graph is irreducible, and classifies
 * each class as transient or persistent (including absorbing states).
 *
 * @param partition The partition of the graph.
 * @param links The inter-class links.
 */
void print_graph_characteristics(t_partition, t_link_list);

#endif //LINKS_H
