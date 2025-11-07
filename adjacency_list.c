//
// Created by thomas on 10/20/25.
//

#include <math.h>
#include "adjacency_list.h"
#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#define APROXIMITY_RANGE 0.1

t_adj_list * create_empty_adj_list(const int size) {
    t_adj_list * new_adj_list = (t_adj_list *) malloc(sizeof(t_adj_list));
    t_list ** inner_list = (t_list **) malloc(sizeof(t_list*)*size);

    new_adj_list->size = size;
    new_adj_list->inner_list = inner_list;

    for (int i = 0; i < size; ++i) {
        inner_list[i] = create_empty_list();
    }

    return new_adj_list;
}

void free_adj_list(t_adj_list * adj_list) {
    if (adj_list == NULL || adj_list->inner_list == NULL) {printf("Erreur: liste d'adjacence invalide\n"); return;}

    t_list ** a_list = adj_list->inner_list;
    const int size = adj_list->size;

    for (int i = 0; i < size; ++i) {
        free(a_list[i]);
    }

    free(adj_list);
}

void print_adj_list(const t_adj_list * adj_list) {
    if (adj_list == NULL || adj_list->inner_list == NULL) {printf("Erreur: liste d'adjacence invalide\n"); return;}

    t_list ** a_list = adj_list->inner_list;
    const int size = adj_list->size;

    for (int i = 0; i < size; ++i) {
        printf("List %d : ",i+1);
        print_list(a_list[i]);
    }


}
void add_cell_to_adj_list(t_adj_list * adj_list, const int list_index, const int cell_index_to, const float cell_value) {
    if (adj_list == NULL || adj_list->inner_list == NULL) {printf("Erreur: liste d'adjacence invalide\n"); return;}
    if (list_index < 0 || list_index >= adj_list->size) {printf("Erreur: index de liste invalide\n"); return;}
    if (cell_index_to < 0 || cell_index_to >= adj_list->size) {printf("Erreur: index de cellule invalide\n"); return;}

    add_cell_to_list(adj_list->inner_list[list_index], cell_index_to, cell_value);
}

int validate_adj_list(t_adj_list * adj_list) {
    if (adj_list == NULL || adj_list->inner_list == NULL) {printf("Erreur: liste d'adjacence invalide\n"); return 0;}
    
    
    t_list ** a_list = adj_list->inner_list;
    const int size = adj_list->size;
    int is_valid = 1;

    for (int i = 0; i < size; ++i) {
        float sum = 0;
        t_cell * cell = a_list[i]->head;
        while (cell != NULL) {
            sum += cell->value;
            cell = cell->next;
        }

        if (a_list[i]->head != NULL) {
            if (fabs(sum - 1.0) > APROXIMITY_RANGE) {
                printf("La somme des probabilites du sommet %d est %.2f\n", i+1, sum);
                is_valid = 0;
            }
        }
    }

    if (is_valid) {
        printf("Le graphe est un graphe de Markov\n");
    } else {
        printf("Le graphe n'est pas un graphe de Markov\n");
    }
    return is_valid;
}

char * getId(int num) {
    static char id[10];
    id[0] = '\0';
    
    if (num <= 0) return id;
    
    num--; // Convert to 0-based index
    
    int pos = 0;
    do {
        id[pos++] = 'A' + (num % 26);
        num = num / 26 - 1;
    } while (num >= 0);
    
    // Reverse the string
    for (int i = 0; i < pos / 2; i++) {
        char temp = id[i];
        id[i] = id[pos - 1 - i];
        id[pos - 1 - i] = temp;
    }
    id[pos] = '\0';
    
    return id;
}

void generate_mermaid_file(const t_adj_list * adj_list, const char * filename) {
    if (adj_list == NULL || adj_list->inner_list == NULL) {
        printf("Erreur: liste d'adjacence invalide\n");
        return;
    }
    
    if (filename == NULL) {
        printf("Erreur: nom de fichier NULL\n");
        return;
    }

    FILE * file = fopen(filename, "w");
    if (file == NULL) {
        printf("Erreur: impossible d'ouvrir le fichier %s\n", filename);
        return;
    }
    
    // Write configuration header
    fprintf(file, "---\n");
    fprintf(file, "config:\n");
    fprintf(file, "  layout: elk\n");
    fprintf(file, "  theme: neo\n");
    fprintf(file, "  look: neo\n");
    fprintf(file, "---\n");
    fprintf(file, "flowchart LR\n");
    
    // Write vertices
    for (int i = 0; i < adj_list->size; i++) {
        fprintf(file, "  %s((%d))\n", getId(i + 1), i + 1);
    }
    
    // Write edges
    for (int i = 0; i < adj_list->size; i++) {
        t_cell * cell = adj_list->inner_list[i]->head;
        while (cell != NULL) {
            char from_id[10];
            char to_id[10];
            strcpy(from_id, getId(i + 1));

            strcpy(to_id, getId(cell->index_to));
            fprintf(file, "  %s -->|%.2f|%s\n", 
                    from_id, 
                    cell->value, 
                    to_id);
            cell = cell->next;
        }
    }
    
    fclose(file);
    printf("Fichier Mermaid genere: %s\n", filename);
}
