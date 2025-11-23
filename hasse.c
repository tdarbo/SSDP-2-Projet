//
// Created by thomas on 23/11/2025.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hasse.h"

void remove_transitive_links(t_link_list *list)
{
    int i = 0;
    while (i < list->size)
    {
        t_link link1 = list->links[i]; // Supposons que c'est A -> C
        int j = 0;
        int to_remove = 0;

        while (j < list->size && !to_remove)
        {
            if (j != i)
            {
                t_link link2 = list->links[j]; // Cherchons A -> B

                // Si même point de départ (A)
                if (link1.source == link2.source)
                {
                    // On cherche maintenant un lien B -> C
                    int k = 0;
                    while (k < list->size && !to_remove)
                    {
                        if (k != j && k != i)
                        {
                            t_link link3 = list->links[k];

                            // Si link3 part de link2.target (B) et arrive à link1.target (C)
                            if ((link3.source == link2.target) && (link3.target == link1.target))
                            {
                                to_remove = 1; // On a trouvé A->B->C, donc A->C est transitif
                            }
                        }
                        k++;
                    }
                }
            }
            j++;
        }

        if (to_remove)
        {
            // Remove link1 by replacing it with the last link
            list->links[i] = list->links[list->size - 1];
            list->size--;
            // On n'incrémente pas i car on doit tester le nouveau lien qui a pris cette place
        }
        else
        {
            i++;
        }
    }
}
void generate_hasse_mermaid_file(const t_link_list *list, const char *filename) {
    if (list == NULL || list->links == NULL) {
        printf("Erreur: liste de liens invalide\n");
        return;
    }
    
    if (filename == NULL) {
        printf("Erreur: nom de fichier NULL\n");
        return;
    }

    FILE *file = fopen(filename, "w");
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
    fprintf(file, "flowchart TB\n");
    
    int max_vertex = 0;
    for (int i = 0; i < list->size; i++) {
        if (list->links[i].source + 1 > max_vertex) {
            max_vertex = list->links[i].source + 1;
        }
        if (list->links[i].target + 1 > max_vertex) {
            max_vertex = list->links[i].target + 1;
        }
    }
    
    // Write vertices as classes/nodes
    for (int i = 1; i <= max_vertex; i++) {
        fprintf(file, "  %s([C%d])\n", getId(i), i);
    }
    
    // Write edges (links between classes)
    for (int i = 0; i < list->size; i++) {
        char from_id[10];
        char to_id[10];
        strcpy(from_id, getId(list->links[i].source + 1));
        strcpy(to_id, getId(list->links[i].target + 1));
        fprintf(file, "  %s --> %s\n", from_id, to_id);
    }
    
    fclose(file);
    printf("Fichier Mermaid du diagramme de Hasse genere: %s\n", filename);
}
