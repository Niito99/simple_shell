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

    if (strcmp(args[0], "exit") == 0)
	    exit(0);

    if (strcmp(args[0], "env") == 0)
    {
        char *env_var = getenv("PATH");
        if (env_var != NULL)
        {
            printf("PATH=%s\n", env_var);
        }
	return;
    }

    char *path = getenv("PATH");
    char *pathcpy = strdup(path);
    char *token = strtok(pathcpy, ":");

    int search = 0;

    while (token != NULL)
    {
	    char full_path[MAX_PATH_SIZE];
	    snprintf(full_path, sizeof(full_path), "%s/%s", token, args[0]);

	    if (access(full_path, X_OK) == 0)
	    {
		    search = 1;
		    pid_t pid = fork();
		    if (pid < 0) 
		    {
			    perror("Fork error");
			    exit(EXIT_FAILURE);
		    }
		    else if (pid == 0) 
		    {
			    if (execv(full_path, args) == -1) 
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
		    break;
		       
	    }
	    token = strtok(NULL, ":");
    }

    free(pathcpy);
    if (!search)
	    printf("Command not found: %s\n", args[0]);

}

