//
// Created by thomas on 11/10/25.
//

#include "tarjan.h"
#include <stdlib.h>
#include <stdio.h>

#define NULL_ID -99

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
    if (pil->size == 0) return NULL_ID;
    pil->size--;
    return pil->pile[pil->size];
}
void push(t_pile* pil, int val)
{
    if (pil->size == SIZE) return;
    pil->pile[pil->size] = val;
    pil->size++;
}

t_vertex* get_vertex(t_vertex_list* list, int id) {
    if (list == NULL || list->vertex == NULL) return NULL;
    if (id <= 0) return NULL;
    return &list->vertex[id - 1];
}



void parcours(
    t_vertex* v,
    int* num,
    t_pile* P,
    t_partition* partition,
    t_adj_list* graph,
    t_vertex_list* v_list
    ){

    if (v == NULL) return;

    v->number = *num;
    v->accces_number = *num;
    (*num)++;
    push(P, v->id);
    v->inStack = TRUE;

    t_list* successor = graph->inner_list[v->id-1];
    t_cell* current = successor->head;

    while (current != NULL)
    {
        t_vertex* w = get_vertex(v_list, current->index_to);
        if (w == NULL){ current = current->next; continue; }

        if (w->number == -1)
        {
            parcours(w, num, P, partition, graph, v_list);
            v->accces_number = min(v->accces_number, w->accces_number);
        }
        else if (w->inStack)
        {
            v->accces_number = min(v->accces_number, w->number);
        }

        current = current->next;
    }

    if (v->accces_number == v->number)
    {
        t_class c = create_class(partition->size);
        int popped_id = -1;
        do {
            int pid = pop(P);
            if (pid == NULL_ID) break;
            t_vertex* w = get_vertex(v_list, pid);
            if (w == NULL) break;
            w->inStack = FALSE;
            c.index[c.size] = w->id;
            c.size++;
            popped_id = w->id;
        } while (popped_id != v->id);
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
        t_vertex* v = &vertex_list.vertex[i];
        if (v->number == -1)
        {
            parcours(v, &num, &P, &partition, graph, &vertex_list);
        }
    }

    destroy_pile(&P);
    suppress_vertex_list(vertex_list);
    return partition;
}


int min(const int a,const int b)
{
    return a < b ? a : b;
}


