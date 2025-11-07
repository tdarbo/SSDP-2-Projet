//
// Created by thomas on 10/20/25.
//

#ifndef SSDP_2_PROJET_FILELOADER_H
#define SSDP_2_PROJET_FILELOADER_H

#include <stdlib.h>
#include "adjacency_list.h"

t_adj_list* list_import(const char*);
void list_export(t_adj_list);

#endif //SSDP_2_PROJET_FILELOADER_H