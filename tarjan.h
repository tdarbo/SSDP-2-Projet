//
// Created by thomas on 11/10/25.
//

#ifndef SSDP_2_PROJET_TARJAN_H
#define SSDP_2_PROJET_TARJAN_H

#include "adjacency_list.h"
#include "partition.h"
#include "vertex.h"
#include "class.h"


#define BOOL int
#define TRUE 1
#define FALSE 0

struct s_pile{
    int* pile;
    int size;
}typedef t_pile;

/**
 * @brief Creates a new empty stack for Tarjan's algorithm.
 *
 * @return t_pile A new stack initialized with empty content.
 */
t_pile create_pile();

/**
 * @brief Frees the memory allocated for a stack.
 *
 * @param pil Pointer to the stack to destroy.
 */
void destroy_pile(t_pile*);

/**
 * @brief Removes and returns the top element from the stack.
 *
 * @param pil Pointer to the stack.
 * @return int The value popped from the stack, or NULL_ID if empty.
 */
int pop(t_pile*);

/**
 * @brief Pushes a value onto the stack.
 *
 * @param pil Pointer to the stack.
 * @param val The value to push.
 */
void push(t_pile*, int);

/**
 * @brief Retrieves a vertex from a vertex list by its ID.
 *
 * @param list Pointer to the vertex list.
 * @param id The ID of the vertex to retrieve (1-based).
 * @return t_vertex* Pointer to the vertex, or NULL if not found.
 */
t_vertex* get_vertex(t_vertex_list*, int id);

/**
 * @brief Performs a depth-first search as part of Tarjan's algorithm.
 *
 * Recursively explores the graph to identify strongly connected components.
 *
 * @param v Pointer to the current vertex being explored.
 * @param num Pointer to the current numbering counter.
 * @param P Pointer to the stack used by the algorithm.
 * @param partition Pointer to the partition being built.
 * @param graph Pointer to the adjacency list of the graph.
 * @param v_list Pointer to the list of all vertices.
 */
void parcours(t_vertex*, int*, t_pile*, t_partition*, t_adj_list* graph,t_vertex_list*);

/**
 * @brief Executes Tarjan's algorithm to find strongly connected components.
 *
 * @param graph Pointer to the adjacency list of the graph.
 * @return t_partition A partition of the graph into strongly connected components.
 */
t_partition tarjan(t_adj_list*);

/**
 * @brief Returns the minimum of two integers.
 *
 * @param a First integer.
 * @param b Second integer.
 * @return int The smaller of the two values.
 */
int min(int,int);




#endif //SSDP_2_PROJET_TARJAN_H
