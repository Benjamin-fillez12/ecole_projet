
/*
    fichier ref de truncate.h.
*/

#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <fcntl.h>
#include <string.h>
#include <windows.h>
#include <sys/stat.h>

int change_file_size(FILE *,size_t);
int resolve_file_err(FILE *,char *);
size_t get_file_size(char *)
