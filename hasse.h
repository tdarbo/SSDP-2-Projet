//
// Created by thomas on 23/11/2025.
//

#ifndef HASSE_H
#define HASSE_H

#include "links.h"

/**
 * @brief Removes transitive links from a link list to create a Hasse diagram.
 *
 * A link A->C is transitive if there exists links A->B and B->C.
 * This function removes all such transitive links, keeping only direct relationships.
 *
 * @param list Pointer to the link list to process.
 */
void remove_transitive_links(t_link_list *list);
void generate_hasse_mermaid_file(const t_link_list *list, const char *filename);

#endif //HASSE_H
