#include <stdio.h>
#include "list.h"
#include "file_loader.h"
#include "adjacency_list.h"

int main(void) {
    printf("Adjacency List Example\n");
    t_adj_list* adj_list = list_import("D:/0_Code/C++/SSDP-2-Projet/data/exemple1.txt");
    printf("Printlist:\n");
    print_adj_list(adj_list);
    validate_adj_list(adj_list);
    free_adj_list(adj_list);
    return 0;
}