#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// Thread function
void* run(void* arg) {
    char* msg = (char*)arg;
    printf("Thread says: %s\n", msg);
    return NULL;
}

int main() {
    pthread_t thread;
    pthread_attr_t attr;

    // Initialize the thread attribute
    pthread_attr_init(&attr);
    
    
    //pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED); //cannot be joined


    // Create the thread
    if (pthread_create(&thread, &attr, run, "Hello from the thread!") != 0) {
        perror("Failed to create the thread");
        return 1;
    }

    // Wait for the thread to terminate
    if (pthread_join(thread, NULL) != 0) {
        perror("Failed to join the thread");
        return 2;
    }

    // Clean up the attribute
    pthread_attr_destroy(&attr);
    printf("Thread finished execution.\n");

    return 0;
}

