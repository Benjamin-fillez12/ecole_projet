#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>

char *get_local_time_buffer(struct tm*);
void put_local_time_buffer(FILE *,char *, char *);
