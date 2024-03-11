#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sig_handler(int signum) {
    printf("Caught signal %d\n", signum);
    if (signum == SIGQUIT) {
        // Perform any specific actions for SIGQUIT before quitting, e.g., cleanup
        printf("Quitting...\n");
        exit(0); // Terminate program
    }
}

int main() {
    // Register signal handlers
    signal(SIGINT, sig_handler);
    signal(SIGTSTP, sig_handler);
    signal(SIGQUIT, sig_handler);

    // Loop indefinitely to keep the program running
    while(1) {
        sleep(1);
    }
    return 0;
}
