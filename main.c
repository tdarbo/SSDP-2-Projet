#include <stdio.h>
#include "list.h"
#include "file_loader.h"
#include "adjacency_list.h"
#include "tarjan.h"
#include "matrix.h"

int main(void) {
    printf("Adjacency List Example\n");
    t_adj_list* adj_list = list_import("../data/exemple_valid_step3.txt");
    printf("Printlist:\n");
    print_adj_list(adj_list);
    validate_adj_list(adj_list);
    t_matrix matrix = create_adj_matrix(*adj_list);
    print_matrix(matrix);
    free_matrix(matrix);
    generate_mermaid_file(adj_list, "../export/graph.txt");

    t_partition partition = tarjan(adj_list);
    print_partition(&partition);


    free_adj_list(adj_list);
    return 0;
}