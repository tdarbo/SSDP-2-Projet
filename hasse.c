//
// Created by thomas on 23/11/2025.
//

#include <stdlib.h>
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