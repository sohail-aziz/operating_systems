#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void* threadFunction(void* arg) {
    printf("Thread is running with custom attributes.\n");
    return NULL;
}

int main() {
    pthread_t thread;
    pthread_attr_t attr;
    struct sched_param param;

    // Initialize the thread attributes
    pthread_attr_init(&attr);

    // Set the detach state
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    //pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE); //or joinable

    // Set custom stack size
    size_t stacksize = 1024 * 1024; // 1 MB
    void *stackaddr = malloc(stacksize); // Allocate memory for the stack
    if (stackaddr == NULL) {
        perror("Failed to allocate memory for stack");
        return 1;
    }
    pthread_attr_setstack(&attr, stackaddr, stacksize);

    // Set the scheduling policy and explicit priority
    pthread_attr_setschedpolicy(&attr, SCHED_FIFO);
    param.sched_priority = sched_get_priority_max(SCHED_FIFO); // Use the maximum priority for FIFO
    pthread_attr_setschedparam(&attr, &param);

    // Set the scope to system-wide (PTHREAD_SCOPE_SYSTEM)
    pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);

    // Create the thread with the specified attributes
    if (pthread_create(&thread, &attr, threadFunction, NULL) != 0) {
        perror("Failed to create the thread");
        // Free the allocated stack in case of failure
        free(stackaddr);
        pthread_attr_destroy(&attr);
        return 1;
    }

    // Since the thread is detached, we do not need to join it
    printf("Thread created, it is detached with a custom stack size, scheduling policy, and scope.\n");

    // Clean up
    pthread_attr_destroy(&attr);
    sleep(1);  // Allow some time for the thread to run

    // Free the stack memory after the thread is likely done
    free(stackaddr);

    return 0;
}

