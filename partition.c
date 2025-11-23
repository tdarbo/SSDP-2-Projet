//
// Created by thomas on 11/10/25.
//

#include "partition.h"

#include <stdio.h>
#include <stdlib.h>
#include "class.h"

t_partition create_partition()
{
    t_partition p;
    t_class* list = malloc(sizeof(t_class)*PARTITION_MAX_SIZE);
    p.classes=list;
    p.size=0;
    return p;
}

void print_partition(t_partition* p)
{
    for (int i = 0; i < p->size; i++)
    {
        print_class(&(p->classes[i]));
    }
}

void delete_partition(t_partition* p)
{
    if (p == NULL || p->classes == NULL) return;
    
    // Libérer chaque classe individuellement
    for (int i = 0; i < p->size; i++) {
        delete_class(&(p->classes[i]));
    }
    
    // Libérer le tableau de classes
    free(p->classes);
    p->classes = NULL;
    p->size = 0;
}
