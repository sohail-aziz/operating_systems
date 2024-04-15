#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 3

// Shared global variable
int shared_variable = 0;

// Thread-specific global variable
__thread int thread_specific_variable = 0;

// Function executed by each thread
void* thread_function(void *arg) {
    int *thread_number = (int *)arg;

    // Increment shared variable
    shared_variable++;

    // Increment thread-specific variable
    thread_specific_variable++;

    printf("Thread %d: Shared Variable = %d, Thread-Specific Variable = %d\n", *thread_number, shared_variable, thread_specific_variable);

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_args[i] = i + 1;
        if(pthread_create(&threads[i], NULL, thread_function, &thread_args[i])) {
            fprintf(stderr, "Error creating thread\n");
            return 1;
        }
    }

    // Wait for threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Main Thread: Shared Variable = %d, Thread-Specific Variable = %d\n", shared_variable, thread_specific_variable);

    return 0;
}

