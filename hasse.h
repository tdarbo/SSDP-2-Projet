//
// Created by thomas on 23/11/2025.
//

#ifndef HASSE_H
#define HASSE_H

#include "links.h"

void remove_transitive_links(t_link_list *list);
void generate_hasse_mermaid_file(const t_link_list *list, const char *filename);

#endif //HASSE_H
