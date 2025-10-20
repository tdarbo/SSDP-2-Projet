//
// Created by Helytre on 10/20/25.
//

#include <stdio.h>

#ifndef SSDP_2_PROJET_LOGGER_H
#define SSDP_2_PROJET_LOGGER_H

FILE* logger_init();
void logger_close(FILE*);
void logger_write(FILE*, char*);
void logger_test(int test, char* valid, char* error);

#endif //SSDP_2_PROJET_LOGGER_H