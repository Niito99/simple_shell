#include "main.h"

void exec(const char *command) 
{
    // Check if the command contains a '/' indicating a full path
    if (strchr(command, '/') != NULL) 
    {
        char *args[64];
        char *token = strtok((char *)command, " ");
        int i = 0;

        while (token != NULL && i < 63) 
        {
            args[i] = token;
            token = strtok(NULL, " ");
            i++;
        }
        args[i] = NULL;

        // Check if the full path exists and is executable
        if (access(args[0], X_OK) == 0) 
        {
            pid_t pid = fork();

            if (pid < 0) 
            {
                perror("Fork error");
                exit(EXIT_FAILURE);
            } 
            else if (pid == 0) 
            {
                if (execv(args[0], args) == -1) 
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
        else 
        {
            printf("Command not found or not executable: %s\n", command);
        }
    } 
    else 
    {
        // Command does not contain a '/', check if it exists in PATH
        char *path_env = getenv("PATH");
        char *path = strdup(path_env);
        char *token = strtok(path, ":");
        bool command_found = false;

        while (token != NULL) 
        {
            char full_path[256]; // Assuming a reasonable path length
            snprintf(full_path, sizeof(full_path), "%s/%s", token, command);

            // Check if the full path exists and is executable
            if (access(full_path, X_OK) == 0) 
            {
                command_found = true;
                pid_t pid = fork();

                if (pid < 0) 
                {
                    perror("Fork error");
                    exit(EXIT_FAILURE);
                } 
                else if (pid == 0) 
                {
                    char *exec_args[2];
                    exec_args[0] = strdup(full_path);
                    exec_args[1] = NULL;
                    
                    if (execv(full_path, exec_args) == -1) 
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

        free(path);

        if (!command_found) 
        {
            printf("Command not found: %s\n", command);
        }
    }
}


