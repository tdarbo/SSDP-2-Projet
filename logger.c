//
// Created by Helytre on 10/20/25.
//

#include "logger.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LOGGING 1
#define SAVING 1

FILE* logger_init(){
    if(!LOGGING) return NULL;
    time_t currentTime;
    time(&currentTime);
    char* date = ctime(&currentTime);
    strcat(date, ".txt");
    FILE* logs = fopen(date,"w");
    return logs;
}

void logger_close(FILE* logs){
    if(LOGGING) fclose(logs);
}

void logger_write(FILE* logs, char* msg){
    fprintf(logs, "%s", msg);
}

void logger_test(int test, char* valid, char* error){
    if (test){
        fprintf(logger_init(), "ERROR : %s", error);
    }else{
        fprintf(logger_init(), "VALID : %s", valid);
    }
}