//
// Created by thomas on 11/10/25.
//

#ifndef SSDP_2_PROJET_PARTITION_H
#define SSDP_2_PROJET_PARTITION_H
#define PARTITION_MAX_SIZE 100

#include "class.h"

struct s_partition {

    t_class* classes;
    int size;

} typedef t_partition;


t_partition create_partition();
void print_partition(t_partition*);
void delete_partition(t_partition*);

#endif //SSDP_2_PROJET_PARTITION_H