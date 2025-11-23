#include <stdio.h>
#include "list.h"
#include "file_loader.h"
#include "adjacency_list.h"
#include "tarjan.h"
#include "links.h"
#include "matrix.h"

int main(void) {
    printf("Adjacency List Example\n");
    t_adj_list* adj_list = list_import("../data/exemple_valid_step3.txt");
    printf("Printlist:\n");
    print_adj_list(adj_list);
    validate_adj_list(adj_list);
    t_matrix matrix = create_adj_matrix(*adj_list);
    print_matrix(matrix);
    generate_mermaid_file(adj_list, "../export/graph.txt");

    t_partition partition = tarjan(adj_list);
    print_partition(&partition);

/*
    printf("\n=== Test de subMatrix ===\n");
    for (int i = 0; i < partition.size; i++) {
        printf("\nSous-matrice pour la classe %d (taille: %d):\n", i, partition.classes[i].size);
        t_matrix sub_mat = subMatrix(matrix, partition, i);
        if (sub_mat.size > 0) {
            print_matrix(sub_mat);
            free_matrix(&sub_mat);
        }
    }
*/
    // Calcul des distributions stationnaires par classe
    printf("\n=== Distributions stationnaires par classe ===\n");
    
    for (int i = 0; i < partition.size; i++) {
        printf("\nClasse %d (taille: %d): \n", i, partition.classes[i].size);
        
        t_matrix sub = subMatrix(matrix, partition, i);
        if (sub.size == 0) {
            printf("  Classe vide\n");
            continue;
        }
        t_matrix result = stationary_distribution(sub);
        printf("Sous-matrice => ");
        print_matrix(sub);
        free_matrix(&sub);
        printf("Resultat => ");
        print_matrix(result);
        free_matrix(&result);
    }

    free_matrix(&matrix);
    free_adj_list(adj_list);
    return 0;
}