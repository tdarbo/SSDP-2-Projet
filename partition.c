//
// Created by thomas on 11/10/25.
//

#include "partition.h"

#include <stdio.h>
#include <stdlib.h>

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

void delete_partition(t_partition p)
{
    free(p.classes);
}
