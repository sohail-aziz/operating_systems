#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main() {
    pid_t pid = fork();

    if (pid == -1) {
        // Fork failed
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        // Parent process
        printf("Parent process PID: %d\n", getpid());
        printf("Parent process waiting...\n");
        // Wait for a signal to arrive
        pause();
    } else {
        // Child process
        printf("Child process PID: %d\n", getpid());
        sleep(2); // Ensure that the parent is waiting

        // Send SIGKILL to parent
        printf("Child sending SIGKILL to parent PID: %d\n", getppid());
        if (kill(getppid(), SIGKILL) == -1) {
            perror("kill");
            exit(EXIT_FAILURE);
        }

        // Child exits
        exit(EXIT_SUCCESS);
    }

    return 0;
}
