#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Global variable - shared by all threads
int globalVariable = 0;

// Thread function
void* thread_function(void *arg) {
    int localVariable = 0; // Local variable - private to each thread

    // Increment the global and local variable
    globalVariable++;
    localVariable++;

    printf("Thread %d, Local: %d, Global: %d\n", *(int*)arg, localVariable, globalVariable);

    return NULL;
}

int main() {
    pthread_t threads[2];
    int threadIds[2] = {1, 2};

    // Create threads
    for (int i = 0; i < 2; i++) {
        if (pthread_create(&threads[i], NULL, thread_function, &threadIds[i])) {
            fprintf(stderr, "Error creating thread\n");
            return 1;
        }
    }

    // Wait for threads to finish
    for (int i = 0; i < 2; i++) {
        pthread_join(threads[i], NULL);
    }
    

    printf("Final value of Global Variable: %d",globalVariable);
    
    return 0;
}
    

