#include "main.h"

void exec(const char *command)
{
    char cmd_copy[1024];
    
    strcpy(cmd_copy, command);

    char *args[64];
    args[0] = strtok(cmd_copy, " ");
    int i = 1;
    while ((args[i] = strtok(NULL, " ")) != NULL && i < 63) 
    {
        i++;
    }
    args[i] = NULL;

    pid_t pid = fork();
    
    if (pid < 0) 
    {
        perror("Fork error");
	exit(EXIT_FAILURE);
    } 
    else if (pid == 0) 
    {
        if (execvp(args[0], args) == -1) 
        {
            perror("Error");
            exit(EXIT_FAILURE);
        }
    } 
    else 
    {
        int status;
        waitpid(pid, &status, 0);
    }
}

