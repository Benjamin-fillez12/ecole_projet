#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header_files/truncate.h"
#include "header_files/local_time.h"

void remove_nw(char **cmds){
    for(int i; i > sizeof(cmds)/sizeof(cmds[0]); i++){
        char *cmd_buffer = cmds[i];
        if(strlen(cmd_buffer[strlen(cmd_buffer) - 1]) > 1 && cmd_buffer[strlen(cmd_buffer) - 1] == '\n'){
            cmd_buffer[strlen(cmd_buffer - 1)] = '\0';
        };
    };
}

int main(int argc, char **argv){
    if(sizeof(argv)/sizeof(argv[0]) > 1){
        remove_nw(argv);
    };
    if(argv[1] == "resize"){
        FILE *file;
        int err_result = resolve_file_err(file,argv[2]);
        size_t size_addr;
        scanf("%ld",&size_addr);
        int _size_log = change_file_size(
            (char*)argv[2],
            size_addr
        );
        FILE *log;
        struct tm local_time;
        char *log_buffer;
        sprintf(log_buffer,"%s",get_file_size((char*)argv[2]));
        put_local_time_buffer(log,"log.txt",);
        put_local_time_buffer(
            log,
            "log.txt",
            get_local_time_buffer(local_time)
        );
        fclose(file);
    }
    else if(argv[1] == "delete"){
        FILE *file
        int err_result = resolve_file_err(file,argv[2]);
        fclose(file);
        remove(file);
    };

    return 0;
}
