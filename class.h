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

/**
 * @brief Creates a new class (strongly connected component) with the specified name.
 *
 * @param name The identifier for the class.
 * @return t_class A new class initialized with empty vertex list.
 */
t_class create_class(int);

/**
 * @brief Prints the contents of a class to the console.
 *
 * @param c Pointer to the class to print.
 */
void print_class(const t_class*);

/**
 * @brief Frees the memory allocated for a class.
 *
 * @param c Pointer to the class to delete.
 */
void delete_class(t_class*);

#endif //SSDP_2_PROJET_CLASS_H