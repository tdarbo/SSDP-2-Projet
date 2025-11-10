//
// Created by thomas on 11/10/25.
//

#include "tarjan.h"

#include <stdlib.h>


t_pile create_pile()
{
    t_pile new_pile;
    new_pile.pile = malloc(sizeof(int)*SIZE);
    new_pile.size = 0;
    return new_pile;
}
void destroy_pile(t_pile* pil)
{
    free(pil->pile);
    pil->pile = NULL;
    pil->size = 0;
}
int pop(t_pile* pil)
{
    pil->size--;
    return pil->pile[pil->size];
}
void push(t_pile* pil, int val)
{
    pil->pile[pil->size] = val;
    pil->size++;
}
void delete(t_pile* pil){
    pil->size--;
}
