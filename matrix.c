//
// Created by matth on 20/11/2025.
//

#include "matrix.h"

t_matrix create_empty_matrix(int size){
    t_matrix new_matrix;
    new_matrix.size = size;
    if (new_matrix.size == 0) {
        new_matrix.values = NULL;
        return new_matrix;
    }
    new_matrix.values = calloc(size,sizeof(float*));
    for (int i=0; i<size; i++){
        new_matrix.values[i] = calloc(size,sizeof(float));
    }
    return new_matrix;
}

t_matrix create_adj_matrix(t_adj_list list){
    t_matrix new_matrix = create_empty_matrix(list.size);
    if (new_matrix.values == NULL){
        return new_matrix;
    }
    for (int i=0; i<list.size; i++){
        t_cell* cur = list.inner_list[i]->head;
        while (cur != NULL){
            new_matrix.values[i][cur->index_to-1] = cur->value;
            cur = cur->next;
        }
    }
    return new_matrix;
}

void free_matrix(t_matrix* matrix){
    for(int i = 0; i < matrix->size; i++){
        free(matrix->values[i]);
    }
    free(matrix->values);
    matrix->values = NULL;
    matrix->size = 0;
}

t_matrix copy_matrix(t_matrix matrix){
    t_matrix new_matrix;
    new_matrix.size = matrix.size;
    if (new_matrix.size == 0){
        new_matrix.values = NULL;
        return new_matrix;
    }
    new_matrix.values = malloc(matrix.size*sizeof(float*));
    for (int i=0; i<matrix.size; i++){
        new_matrix.values[i] = malloc(matrix.size*sizeof(float));
        for (int j=0; j<matrix.size; j++)
        {
            new_matrix.values[i][j] = matrix.values[i][j];
        }
    }
    return new_matrix;
}

void mult_matrix(t_matrix matrix_a, t_matrix matrix_b){
    t_matrix copy = copy_matrix(matrix_a);
    int size = matrix_a.size;
    float temp;
    for (int i=0; i<size; i++){
        for (int j=0; j<size; j++){
            temp = 0;
            for (int k=0; k<size; k++){
                temp += copy.values[k][j] * matrix_b.values[i][k];
            }
            matrix_a.values[i][j] = temp;
        }
    }
    free_matrix(&copy);
}

float diff_matrix(t_matrix matrix_a, t_matrix matrix_b){
    float val = 0, temp;
    int size = matrix_a.size;
    for (int i=0; i<size; i++){
        for (int j=0; j<size; j++){
            temp = matrix_a.values[i][j] - matrix_b.values[i][j];
            if (temp>=0) val += temp;
            else val -= temp;
        }
    }
    return val;
}

void print_matrix(t_matrix matrix){
    //printf("print matrix of size %d :\n", matrix.size);
    if (matrix.size == 0 || matrix.values == NULL) {
        printf("(empty matrix)\n");
        return;
    }
    for (int i = 0; i < matrix.size; i++){
        for (int j = 0; j < matrix.size; j++){
            printf("%.2f", matrix.values[j][i]);
            if (j < matrix.size - 1) {
                printf(" | ");
            }
        }
        printf("\n");
    }
}

t_matrix subMatrix(t_matrix matrix, t_partition part, int compo_index){
    // Vérification que l'index de la composante est valide
    if (compo_index < 0 || compo_index >= part.size){
        t_matrix empty = create_empty_matrix(0);
        return empty;
    }
    t_class component = part.classes[compo_index];
    int sub_size = component.size;
    // Vérification que la composante a des éléments
    if (sub_size == 0 || component.index == NULL) {
        t_matrix empty = create_empty_matrix(0);
        return empty;
    }
    t_matrix sub_matrix = create_empty_matrix(sub_size);
    // Remplissage
    for (int i = 0; i < sub_size; i++){
        int orig_i = component.index[i] - 1;
        for (int j = 0; j < sub_size; j++){
            int orig_j = component.index[j] - 1;
            sub_matrix.values[i][j] = matrix.values[orig_i][orig_j];
        }
    }
    return sub_matrix;
}

t_matrix stationary_distribution(t_matrix matrix){
    if (matrix.size == 0 || matrix.values == NULL) {
        return matrix;
    }
    t_matrix copy = copy_matrix(matrix), prev;
    float diff;
    int iteration = 1;
    do{
        prev = copy_matrix(copy);
        mult_matrix(copy, matrix);
        diff = diff_matrix(copy, prev);
        free_matrix(&prev);
        iteration++;
    }while (iteration <= MAX_ITERATIONS && diff >= EPSILON_CONVERGENCE);
    if (diff < EPSILON_CONVERGENCE){
        return copy;
    }
    return create_empty_matrix(0);
}

t_matrix stationary_vector(t_matrix matrix, t_matrix vector){
    if (matrix.size == 0 || matrix.values == NULL) {
        return matrix;
    }
    t_matrix copy = copy_matrix(vector), prev, copy_mat = copy_matrix(matrix);
    float diff;
    int iteration = 1;
    do{
        prev = copy_matrix(copy);
        mult_matrix(copy_mat, copy);
        free_matrix(&copy);
        copy = copy_matrix(copy_mat);
        free_matrix(&copy_mat);
        copy_mat = copy_matrix(matrix);
        diff = diff_matrix(copy, prev);
        free_matrix(&prev);
        iteration++;
    }while (iteration <= MAX_ITERATIONS && diff >= EPSILON_CONVERGENCE);
    free_matrix(&copy_mat);
    if (diff < EPSILON_CONVERGENCE){
        return copy;
    }
    return create_empty_matrix(0);
}

t_matrix vector_matrix(float* vect, int size)
{
    t_matrix new_matrix = create_empty_matrix(size);
    for (int i=0; i<size; i++)
    {
        new_matrix.values[0][i] = vect[i];
    }
    return new_matrix;
}

void print_vector(t_matrix vector)
{
    for (int i=0; i<vector.size-1; i++)
    {
        printf("%.2f | ", vector.values[0][i]);
    }
    printf("%.2f\n", vector.values[0][vector.size-1]);
}