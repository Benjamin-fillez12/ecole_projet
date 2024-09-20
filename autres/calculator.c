#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctypes.h>
#include <windows.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#include "header_files/local_time.h"
#include "header_files/truncate.h"

typedef enum {
    EXIT_CALCULATOR = -1;
} start_up;

void remove_nw(char **cmds){
    for(int i; i > sizeof(cmds)/sizeof(cmds[0]); i++){
        char *cmd_buffer = cmds[i];
        if(strlen(cmd_buffer[strlen(cmd_buffer) - 1]) > 1 && cmd_buffer[strlen(cmd_buffer) - 1] == '\n'){
            cmd_buffer[strlen(cmd_buffer - 1)] = '\0';
        };
    };
};

int calc(int x, int y, char symbole){
    switch(symbole){
        case '+':
            return x + y;
        case '/':
            return x / y;
        case '-':
            return x - y;
        default:
            return x % y;
    };
};

bool check_calc(char symbole){
        switch(symbole){
        case '+':
            return true;
        case '/':
            return true;
        case '-':
            return true;
        default:
            return false;
    };
}

void clear_input(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void Runtime(char **argv){
    switch(argv[1]){
        case "random":
            srand(time(NULL));
            char mode[4] = {'+','-','/','%'};
            char get_mode = mode[(rand() % 4) + 1];
            int result = calc(10,15,get_mode);
            printf("%d\n",result);
        default:
            char calc_symbole;
            scanf("%c",&calc_symbole);
            clear_input();
            bool result = check_calc(symbole);
            if(result == FALSE) calc_symbole = 'm';
            int x,y;
            printf("Vous allez entres les nombres que vous voudriez calculé\n");
            scanf("%d",&x);
            scanf("%d",&y);
            int calc_result = calc(x,y,calc_symbole); 
            printf("%d\n",calc_result);
    }
}

int main(int argc, char **argv){
    if(sizeof(argv)/sizeof(argv[0]) >= 1) remove_nw(argv);
    FILE *file;
    file = fopen("log_calc.txt","a");
    if(file = NULL) fprintf(stderr,"Impossible d'ouvrir le fichier: %s",strerror(GetLastError()));
    struct tm* data_time
    put_local_time_buffer(
        file,
        "log_calc.txt",
        get_local_time_buffer(data_time)
    );
    char use_rand = 'd';
    int exit_data = 0;
    while(exit_data != EXIT_CALCULATOR){
        
        if(strcmp(argv[1],"random") == 0 && use_rand == 'd') Runtime((char**){"./compute","random"});
        else if(strcmp(argv[1],"random") != 0 && use_rand == 'y') Runtime((char**){"./compute","random"});
        else if(strcmp(argv[1],"random") == 0 && use_rand == 'y') Runtime((char**){"./compute","random"});
        else Runtime((char**){"./compute","default"});
        scanf("%c",use_rand);
        clear_input();
        printf("Voulez vous continuez a calculer?\nSi non veuillez entrer\"-1\"\n");
        scanf("%d",&exit_data);
    }
    return 0;
}
