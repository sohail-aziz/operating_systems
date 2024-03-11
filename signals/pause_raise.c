#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

// Signal handler function for SIGINT
void sigint_handler(int sig_num) {
    // Inform that SIGINT was caught
    printf("Caught signal %d: SIGINT\n", sig_num);
}

int main() {
    // Register the SIGINT handler
    if (signal(SIGINT, sigint_handler) == SIG_ERR) {
        perror("Signal");
        exit(EXIT_FAILURE);
    }

    // Wait for any signal
    printf("Waiting for SIGINT. Press Ctrl+C...\n");
    pause(); // This will pause the program until a signal is received

    // After receiving SIGINT, let's raise SIGINT programmatically
    printf("Raising SIGINT signal programmatically\n");
    if (raise(SIGINT) != 0) {
        perror("Raise");
        exit(EXIT_FAILURE);
    }

    printf("Program execution continues after raise().\n");

    return 0;
}
