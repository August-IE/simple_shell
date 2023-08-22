#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *location(char *path, char *arg) {
    char *path_cpy = strdup(path);
    char *delim = ":";
    char *pathToken = strtok(path_cpy, delim);
    char *filePath = NULL;

    while (pathToken != NULL) {
        filePath = malloc(strlen(arg) + strlen(pathToken) + 2);
        if (filePath == NULL) {
            perror("Memory allocation failed");
            exit(1);
        }
        
        strcpy(filePath, pathToken);
        strcat(filePath, "/");
        strcat(filePath, arg);

        if (access(filePath, X_OK) == 0) {
            free(path_cpy);
            return filePath;
        }

        free(filePath);
        pathToken = strtok(NULL, delim);
    }

    free(path_cpy);
    return NULL;
}

char *get_loc(char *arg) {
    char *path = getenv("PATH");

    if (path) {
        char *fullPath = location(path, arg);
        return fullPath;
    }

    return NULL;
}

int main() {
    char *executableName = "example"; /* Replace with the actual executable name*/

    char *foundPath = get_loc(executableName);

    if (foundPath) {
        printf("Executable found at: %s\n", foundPath);
        free(foundPath);
    } else {
        printf("Executable not found in PATH.\n");
    }

    return 0;
}
