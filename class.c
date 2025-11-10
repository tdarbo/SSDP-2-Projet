//
// Created by thomas on 11/10/25.
//

#include "class.h"

#include <stdio.h>
#include <stdlib.h>

t_class create_class(int name)
{
    t_class c;
    int* index = malloc(sizeof(int)*CLASS_MAX_SIZE);
    c.index = index;
    c.name = name;
    c.size = 0;
    return c;
}


void delete_class(t_class* c)
{
    free(c->index);
}

void print_class(t_class* c)
{
    printf("\nclass#%d",c->name);
    for (int i = 0; i < c->size; i++)
    {
        printf("%d, ", c->index[i]);
    }
}