#include <stdio.h>
#include "list.h"
#include "file_loader.h"
#include "adjacency_list.h"
#include "tarjan.h"

int main(void) {
    printf("Adjacency List Example\n");
    t_adj_list* adj_list = list_import("../data/exemple2.txt");
    printf("Printlist:\n");
    print_adj_list(adj_list);
    validate_adj_list(adj_list);
    generate_mermaid_file(adj_list, "graph.txt");

    t_partition partition = tarjan(adj_list);
    print_partition(&partition);
    printf("%d\n",partition.size);


    free_adj_list(adj_list);
    return 0;
}