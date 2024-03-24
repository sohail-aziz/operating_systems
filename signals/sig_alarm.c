#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void alarm_handler(int sig) {
    printf("Timer expired. SIGALRM received.\n");
    // Additional code to handle the alarm can go here
}

int main() {
    // Register the signal handler for SIGALRM
    signal(SIGALRM, alarm_handler);

    // Schedule the alarm to go off after 5 seconds
    alarm(5);

    printf("Alarm set for 5 seconds.\n");

    // Pause the program and wait for signals
    pause();

    return 0;
}
