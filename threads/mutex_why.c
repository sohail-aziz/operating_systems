#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_INCREMENTS 10000

// Shared counter
int counter = 0;

// Thread function to increment the counter
void* increment(void* arg) {
    for (int i = 0; i < NUM_INCREMENTS; i++) {
        int temp = counter;  // Read counter
        temp = temp + 1;     // Increment local copy
        counter = temp;      // Write back to counter
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;

    // Creating threads
    pthread_create(&thread1, NULL, increment, NULL);
    pthread_create(&thread2, NULL, increment, NULL);

    // Wait for both threads to finish
    pthread_join(thread1, NULL); //this will block the main thread till thread1 completes.
    pthread_join(thread2, NULL);

    // result
    printf("Expected counter value: %d\n", 2 * NUM_INCREMENTS);
    printf("Actual counter value: %d\n", counter);

    return 0;
}

