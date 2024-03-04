#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 100

int main() {
    int pipeParentToChild[2];
    int pipeChildToParent[2];
    pid_t cpid;
    char buf[BUFFER_SIZE];

    // Create two pipes
    if (pipe(pipeParentToChild) == -1 || pipe(pipeChildToParent) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Fork a child process
    cpid = fork();
    if (cpid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (cpid == 0) {    /* Child process */
        close(pipeParentToChild[1]);  // Close unused write end
        close(pipeChildToParent[0]);  // Close unused read end

        // Read message from parent
        read(pipeParentToChild[0], buf, BUFFER_SIZE);
        printf("Child received: %s\n", buf);

        // Send message to parent
        char *childMsg = "Message from child";
        write(pipeChildToParent[1], childMsg, strlen(childMsg) + 1); // Include '\0'

        close(pipeParentToChild[0]);
        close(pipeChildToParent[1]);
        exit(EXIT_SUCCESS);

    } else {            /* Parent process */
        close(pipeParentToChild[0]);  // Close unused read end
        close(pipeChildToParent[1]);  // Close unused write end

        // Send message to child
        char *parentMsg = "Message from parent";
        write(pipeParentToChild[1], parentMsg, strlen(parentMsg) + 1); // Include '\0'

        // Read response from child
        read(pipeChildToParent[0], buf, BUFFER_SIZE);
        printf("Parent received: %s\n", buf);

        close(pipeParentToChild[1]);
        close(pipeChildToParent[0]);
        wait(NULL);        // Wait for child
        exit(EXIT_SUCCESS);
    }
}

