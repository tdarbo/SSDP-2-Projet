//
// Created by thomas on 11/10/25.
//

#ifndef SSDP_2_PROJET_CLASS_H
#define SSDP_2_PROJET_CLASS_H

#define CLASS_MAX_SIZE 100

struct s_class {

       int name;
       int*index;
       int size;

} typedef t_class;

t_class create_class(int);
void print_class(const t_class*);
void delete_class(t_class*);

#endif //SSDP_2_PROJET_CLASS_H