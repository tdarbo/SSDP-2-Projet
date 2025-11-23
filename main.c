#include <stdio.h>
#include <stdlib.h> // Nécessaire pour exit()
#include "list.h"
#include "file_loader.h"
#include "adjacency_list.h"
#include "tarjan.h"
#include "links.h"

#include "matrix.h"
#include "hasse.h"

#define MAX_SIZE 100

t_adj_list* get_adj_list_selector() {
    int choice, i = 0;

    const char *FILES[] = {
        "../data/exemple1.txt",
        "../data/exemple1_chatGPT_fixed.txt",
        "../data/exemple1_from_chatGPT.txt",
        "../data/exemple2.txt",
        "../data/exemple3.txt",
        "../data/exemple4_2check.txt",
        "../data/exemple_hasse1.txt",
        "../data/exemple_meteo.txt",
        "../data/exemple_scc1.txt",
        "../data/exemple_valid_step3.txt",
        NULL
    };

    printf("====== SELECTIONNEZ UN FICHIER A CHARGER ======\n");

    while (FILES[i] != NULL) {
        printf("  [%d] %s\n", i, FILES[i]);
        i++;
    }

    printf("Saisissez votre choix de (0 a %d) : ", i - 1);

    if (scanf("%d", &choice) != 1 || choice < 0 || choice >= i) {
        printf("\nErreur ; Choix invalide. Chargement de %s.", FILES[0]);
        choice = 0;
    }

    const char* SELECTED_FILE = FILES[choice];
    printf(" -> Chargement de %s\n", SELECTED_FILE);

    t_adj_list* adj_list = list_import(SELECTED_FILE);

    if (adj_list == NULL) {
        printf("Erreur critique : Impossible de charger %s\n", SELECTED_FILE);
        exit(400);
    }
    printf(" -> Fichier %s charge !\n", SELECTED_FILE);
    return adj_list;
}

int test_selector() {
    int choice, i = 0;

    const char *OPTIONS[] = {
        "Partie 1",
        "Partie 2",
        "Partie 3",
        "Toutes les parties",
        NULL
    };

    printf("====== SELECTIONNEZ UN TEST A EFFECTUER ======\n");

    while (OPTIONS[i] != NULL) {
        printf("  [%d] %s\n", i, OPTIONS[i]);
        i++;
    }

    printf("Saisissez votre choix de (0 a %d) : ", i - 1);

    if (scanf("%d", &choice) != 1 || choice < 0 || choice >= i) {
        printf("\nErreur ; Choix invalide. Lancement de %s.", OPTIONS[0]);
        choice = 0;
    }

    const char* SELECTED_FILE = OPTIONS[choice];
    printf(" -> Lancement de %s\n", SELECTED_FILE);

    return choice;
}

void test_partie_1(t_adj_list* adj_list) {

    printf("\n=================================================\n");
    printf("================== PARTIE 1 =====================\n");
    printf("=================================================\n");

    printf("\nETAPE I (Validation graph de markov) : \n");
    const int is_markov = validate_adj_list(adj_list);
    printf("(1.I) IS MARKOV | TEST ");
    if (is_markov) {
        printf("VALIDATE.\n");
    } else {
        printf("FAILED.\n");
    }

    printf("\nETAPE II (Print graph) : \n(1.II)\n");
    print_adj_list(adj_list);

    printf("\nETAPE III (Export vers mermaid) : \n(1.III)\n");
    generate_mermaid_file(adj_list, "../export/test_1.txt");

    printf("\n=================================================\n");
    printf("================== FIN P1 =======================\n");
    printf("=================================================\n");
}

void test_partie_2(t_adj_list* adj_list) {

    printf("\n=================================================\n");
    printf("================== PARTIE 2 =====================\n");
    printf("=================================================\n");

    printf("\nETAPE I (Creation de la partition et affichage des classes) : \n(2.I)\n");
    t_partition partition = tarjan(adj_list);
    print_partition(&partition);

    printf("\nETAPE II (Creation et affichage des liens de classes) : \n(2.II)\n");
    t_link_list class_links = find_inter_class_links(adj_list, partition);
    print_links(class_links);

    printf("\nETAPE III (Export diagramme de Hasse vers mermaid) : \n(2.III)\n");
    generate_hasse_mermaid_file(&class_links, "../export/test_2.txt");

    printf("\nETAPE IV (Affichage caracteristiques du graphe) : \n(2.IV)\n");
    print_graph_characteristics(partition, class_links);

    free_link_list(&class_links);

    printf("\n=================================================\n");
    printf("================== FIN P2 =======================\n");
    printf("=================================================\n");
}

void test_partie_3(t_adj_list* adj_list) {

    printf("\n=================================================\n");
    printf("================== PARTIE 3 =====================\n");
    printf("=================================================\n");

    printf("\nETAPE I (calcul de matrices) : \n(3.I)\n");
    t_matrix matrix = create_adj_matrix(*adj_list);
    t_matrix copy = copy_matrix(matrix);
    t_matrix copy_2 = copy_matrix(matrix);

    for (int i = 0; i < 2; i++) {
        mult_matrix(copy, matrix);
    }
    for (int i = 0; i < 6; i++) {
        mult_matrix(copy_2, matrix);
    }
    printf("affichage de la matrice M :\n");
    print_matrix(matrix);
    printf("affichage de la matrice M^3 :\n");
    print_matrix(copy);
    printf("affichage de la matrice M^7 :\n");
    print_matrix(copy_2);

    free_matrix(&copy);
    free_matrix(&copy_2);

    printf("\nETAPE II (calcul des distributions stationnaires des classes) : \n(3.II)\n");

    t_partition partition = tarjan(adj_list);

    for (int i = 0; i < partition.size; i++) {
        printf("\nClasse %d (taille: %d): \n", i, partition.classes[i].size);
        t_matrix sub = subMatrix(matrix, partition, i);
        if (sub.size == 0) {
            printf("  Classe vide\n");
            continue;
        }

        printf("Affichage de la sous matrice :\n");
        print_matrix(sub);

        t_matrix result = stationary_distribution(sub);

        printf("Affichage du resultat :\n");
        if (result.size == 0 && sub.size != 0){
            printf("Le critere ne fonctionne pas sur cette sous matrice.\n");
        } else {
            print_matrix(result);
        }

        free_matrix(&sub);
        free_matrix(&result);
    }

    free_matrix(&matrix);


    printf("\n=================================================\n");
    printf("================== FIN P3 =======================\n");
    printf("=================================================\n");
}

int main(void) {
    t_adj_list* adj_list = get_adj_list_selector();

    int test_id = test_selector();

    switch (test_id) {

        case 0: {
            test_partie_1(adj_list);
            break;
        }

        case 1 : {
            test_partie_2(adj_list);
            break;
        }

        case 2 : {
            test_partie_3(adj_list);
            break;
        }

        case 3 : {
            test_partie_1(adj_list);
            test_partie_2(adj_list);
            test_partie_3(adj_list);
            break;
        }

        default: {
            printf("Impossible de charger un test. Abandon\n");
            free_adj_list(adj_list);
            return 400;
        }
    }


    printf("\n[System] Liberation de la memoire du graphe...\n");
    free_adj_list(adj_list);


    return 0;
}