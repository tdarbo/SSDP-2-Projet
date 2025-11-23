//
// Created by thomas on 10/20/25.
//

#ifndef SSDP_2_PROJET_FILELOADER_H
#define SSDP_2_PROJET_FILELOADER_H

#include <stdlib.h>
#include "adjacency_list.h"

/**
 * @brief Imports a graph from a text file and creates an adjacency list.
 *
 * The file format should be:
 * First line: number of vertices
 * Following lines: source_vertex destination_vertex weight
 *
 * @param filename The path to the input file.
 * @return t_adj_list* Pointer to the created adjacency list.
 */
t_adj_list* list_import(const char*);

#endif //SSDP_2_PROJET_FILELOADER_H