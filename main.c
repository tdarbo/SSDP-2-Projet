#include <stdio.h>
#include "list.h"
#include "file_loader.h"
#include "adjacency_list.h"

int main(void) {
    printf("Adjacency List Example\n");
    t_adj_list * adj_list = create_empty_adj_list(10);
    printf("create cell 1\n");
    add_cell_to_adj_list(adj_list, 0, 1, 3.14f);
    printf("create cell 2\n");
    add_cell_to_adj_list(adj_list, 0, 2, 2.71f);
    printf("create cell 3\n");
    add_cell_to_adj_list(adj_list, 1, 3, 1.61f);
    printf("Printlist:\n");
    print_adj_list(adj_list);
    validate_adj_list(adj_list);
    list_export(*adj_list);
    free_adj_list(adj_list);
    return 0;
}