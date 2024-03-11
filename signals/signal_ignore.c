#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    // Ignore SIGINT
    signal(SIGINT, SIG_IGN);
    printf("SIGINT is now ignored. Try pressing Ctrl+C. Sleeping for 5 seconds...\n");
    sleep(5);

    // Restore default handling of SIGINT
    signal(SIGINT, SIG_DFL);
    printf("SIGINT now has its default behavior. Try pressing Ctrl+C again. Sleeping for 5 seconds...\n");
    sleep(5);

    return 0;
}
