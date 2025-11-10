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
    if (pil->size == 0) return -99;
    pil->size--;
    return pil->pile[pil->size];
}
void push(t_pile* pil, int val)
{
    if (pil->size == SIZE) return;
    pil->pile[pil->size] = val;
    pil->size++;
}
void delete_pile(t_pile* pil){
    if (pil->size != 0) pil->size--;
}

void parcours(
    t_vertex v,
    int* num,
    t_pile* P,
    t_partition* partition,
    t_adj_list* graph,
    t_vertex_list* v_list
    ){

    v.number = *num;
    v.accces_number = *num;
    *num = *num + 1;
    push(P, v.id);
    v.inStack = TRUE;

    t_list* successor = graph->inner_list[v.id-1];
    t_cell* current = successor->head;

    while (current != NULL)
    {
        if (current == NULL) break;

        const t_vertex w = *v_list[current->index_to].vertex;
        if (w.inStack == FALSE)
        {
            parcours(w,num,P,partition,graph,v_list);
            v.accces_number = min(v.accces_number,w.accces_number);
        }
        else
        {
            v.accces_number = min(v.accces_number,w.number);
        }

        current = current->next;
    }

    if (v.accces_number == v.number)
    {
        t_class c = create_class(partition->size);
        t_vertex w;
        do
        {
            w = *v_list[pop(P)-1].vertex; w.inStack = FALSE;
            c.index[c.size] = w.id;
        } while (w.id != v.id);
        partition->classes[partition->size] = c;
        partition->size++;
    }
}

t_partition tarjan(t_adj_list* graph)
{
    int num = 0;
    t_pile P = create_pile();
    t_partition partition = create_partition();
    t_vertex_list vertex_list = create_vertex_list(*graph);

    for (int i = 0; i < graph->size; i++)
    {
        t_vertex v = vertex_list.vertex[i];
        if (v.number == -1)
        {
            parcours(
                v,
                &num,
                &P,
                &partition,
                graph,
                &vertex_list
            );
        }
    }

    return partition;

    delete_pile(&P);
    suppress_vertex_list(vertex_list);
}


int min(const int a,const int b)
{
    return a < b ? a : b;
}
