#include <stdio.h>
#include "list.h"
#include "file_loader.h"
#include "adjacency_list.h"
#include "tarjan.h"
#include "links.h"

int main(void) {
    printf("Adjacency List Example\n");
    t_adj_list* adj_list = list_import("../data/exemple_valid_step3.txt");
    printf("Printlist:\n");
    print_adj_list(adj_list);
    validate_adj_list(adj_list);
    generate_mermaid_file(adj_list, "../export/graph.txt");

    t_partition partition = tarjan(adj_list);
    print_partition(&partition);

    t_link_list class_links = find_inter_class_links(adj_list, partition);
    print_links(class_links);

    print_graph_characteristics(partition, class_links);

    free_link_list(&class_links);

    free_adj_list(adj_list);
    return 0;
}