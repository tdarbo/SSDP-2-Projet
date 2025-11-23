//
// Created by thomas on 23/11/2025.
//

#include "links.h"
#include <stdlib.h>
#include <stdio.h>

#include "tarjan.h"

t_link_list create_link_list(int capacity) {
    t_link_list list;
    list.links = malloc(sizeof(t_link) * capacity);
    list.size = 0;
    list.capacity = capacity;
    return list;
}

void free_link_list(t_link_list* list) {
    if (list->links != NULL) {
        free(list->links);
        list->links = NULL;
    }
    list->size = 0;
}

int* create_vertex_to_class_map(t_partition partition, int num_vertices) {
    int* map = malloc(sizeof(int) * num_vertices);

    for(int i = 0; i < num_vertices; i++) map[i] = -1;

    for (int class_id = 0; class_id < partition.size; class_id++) {
        t_class current_class = partition.classes[class_id];

        for (int j = 0; j < current_class.size; j++) {
            int vertex_id = current_class.index[j];
            if (vertex_id - 1 < num_vertices) {
                map[vertex_id - 1] = class_id;
            }
        }
    }
    return map;
}

int link_exists(t_link_list list, int src, int tgt) {
    for (int i = 0; i < list.size; i++) {
        if (list.links[i].source == src && list.links[i].target == tgt) {
            return 1;
        }
    }
    return 0;
}

void add_link(t_link_list* list, int src, int tgt) {
    if (list->size >= list->capacity) {
        return;
    }
    list->links[list->size].source = src;
    list->links[list->size].target = tgt;
    list->size++;
}

t_link_list find_inter_class_links(t_adj_list* graph, t_partition partition) {
    t_link_list link_list = create_link_list(partition.size * partition.size + 1);

    int* class_of = create_vertex_to_class_map(partition, graph->size);

    for (int i = 0; i < graph->size; i++) {
        int class_u = class_of[i];

        if (class_u == -1) continue;

        t_cell* current = graph->inner_list[i]->head;
        while (current != NULL) {
            int vertex_v = current->index_to;
            int class_v = class_of[vertex_v - 1];
            if (class_u != class_v && class_v != -1) {
                if (!link_exists(link_list, class_u, class_v)) {
                    add_link(&link_list, class_u, class_v);
                }
            }
            current = current->next;
        }
    }

    free(class_of);
    return link_list;
}

void print_links(t_link_list list) {
    printf("--- Inter-Class Links ---\n");
    if (list.size == 0) {
        printf("No links between classes (Diagramme de Hasse).\n");
    }
    for (int i = 0; i < list.size; i++) {
        printf("Class %d -> Class %d\n", list.links[i].source, list.links[i].target);
    }
    printf("-----------------------------------------\n");
}

void print_graph_characteristics(t_partition partition, t_link_list links) {
    printf("\n === Graph Characteristics ===\n");

    if (partition.size == 1) {
        printf("This graph is IRREDUCIBLE (1 class).\n");
    } else {
        printf("This graph is not IRREDUCIBLE (%d classes).\n", partition.size);
    }
    printf("  ---  \n");


    int *has_outgoing = (int*)calloc(partition.size, sizeof(int));
    if (has_outgoing == NULL) return;
    for (int i = 0; i < links.size; ++i) {
        int src_class = links.links[i].source;
        if (src_class >= 0 && src_class < partition.size) {
            has_outgoing[src_class] = 1;
        }
    }
    for (int i = 0; i < partition.size; ++i) {
        t_class current_class = partition.classes[i];
        printf("Classe %d : ", i);
        if (has_outgoing[i]) {
            printf("TRANSITOIRE\n");
            printf("  -> Les etats {");
            for (int j = 0; j < current_class.size; j++) {
                printf("%d", current_class.index[j]);
                if (j < current_class.size - 1) printf(", ");
            }
            printf("} sont transitoires.\n");
        } else {
            printf("PERSISTANTE\n");
            if (current_class.size == 1) {
                printf("  -> L'etat %d est ABSORBANT.\n", current_class.index[0]);
            } else {
                printf("  -> Les etats {");
                for (int j = 0; j < current_class.size; ++j) {
                    printf("%d", current_class.index[j]);
                    if (j < current_class.size - 1) printf(", ");
                }
                printf("} sont persistants.\n");
            }
        }
        printf("------------------\n");
    }
    free(has_outgoing);
    printf("==== Fin de l'analyse ====\n");
}
