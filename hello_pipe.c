
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int fd[2]; 
    char buffer[100];
    pid_t pid;

    if (pipe(fd) == -1) {
        perror("pipe failed");
        exit(1);
    }

    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid == 0) { // Child process
        close(fd[1]); // Close write end
        read(fd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
        close(fd[0]);
    } else { // Parent process
        close(fd[0]); // Close read end
        char msg[] = "Hello from parent!";
        write(fd[1], msg, sizeof(msg));
        close(fd[1]);
    }

    return 0;
}

