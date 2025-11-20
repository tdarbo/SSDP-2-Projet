//
// Created by thomas on 11/20/25.
//

#ifndef SSDP_2_PROJET_LINK_H
#define SSDP_2_PROJET_LINK_H

#define LINK_ARRAY_SIZE 10

struct s_link {
    int start_class_id;
    int end_class_id;
} typedef t_link;

struct s_link_array
{
    t_link *links;
    int num_links;
} typedef t_link_array;

#endif //SSDP_2_PROJET_LINK_H