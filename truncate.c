/*
    Fichier principale pour changer la taille d'un fichier et de voir si le fichier
    et ouvert correctement.

    Fonctions:

    @change_file_size(char *file, size_t,size)
    @arg: (char *file), argument obligatoire pour le nom du fichier cela permettra de changer correctement la taille de celui ci.
    @arg: (size_t size), argument obligatoire pour savoir la nouvelle taille a mêtre
    @renvoie: {
        0 = succès, 
        1 = erreur
    }

    ----------------------------------

    @resolve_file_err(FILE *file);
    @arg: (FILE *file), argument obligatoire pour avoir le repère du fichier.
    @arg: (char *file_name), argument obligatoire pour savoir qu'elle fichier doit t-on ouvrir.
    @renvoie: {
        0 = succès, 
        1 = erreur
    }
    @exemple:

    int main(int argc, char**argv){
        FILE *file;
        char buffer[file_name_lenght] = "fichier.txt";
        int result = resolve_file_err(file,buffer);
        if(result != 0) printf("Impossible d'ouvrir le fichier\n");

        return 0;
    }
*/

#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <fcntl.h>
#include <string.h>
#include <windows.h>
#include <sys/stat.h>

int change_file_size(char *file,size_t size){
    int log_result;
    if(_open(file,_O_RDWR) == -1){
        fprintf(stderr,"Erreur en ouvrant le fichier: %s\n",strerror(GetLastError()));
        return 1;
    };
    if((result = _chsize(file,size)) == -1){
        fprintf(stderr,"Taile du fichier impossible à modifier; Raison: %s\n",strerror(GetLastError()));
        return 1;
    }
    printf("Taille du fichier change parfaitement, nouvelle taille: %ld\n",_filelenght(file));
    _close(file);
    return 0;
}

int resolve_file_err(FILE *file,char *file_name){  
    rewind(file);
    file = fopen(
        file_name;
        "w"
    );
    if(!file){
        fprintf(stderr,"Impossible d'ouvrir le fichier: %s\n",strerror(GetLastError()));
        return 1;    
    }
    return 0;
}