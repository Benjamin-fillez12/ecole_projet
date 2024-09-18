#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>

#include "header_files/truncate.h"

char *get_local_time_buffer(struct tm* time){
    time = localtime(&(time_t){time(NULL)});
    char *time_buffer = asctime(tm)
    return time_buffer
};

void put_local_time_buffer(FILE *file,char *file_name, char *buffer){
    int is_open = resolve_file_err(file,file_name);
    if(is_open != 0) fprintf(stderr,"Impossible d'ouvrir le fichier: %s\n",strerror(GetLastError())) return 1;
    file = fopen(file_name,"a");
    char *format_buffer;
    strcpy(format_buffer,buffer);
    format_buffer[strlen(format_buffer) - 1] = '\n';
    fputs(format_buffer);
    fclose(file);
}