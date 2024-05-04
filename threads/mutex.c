#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_INCREMENTS 10000

typedef struct {
    int counter;
    pthread_mutex_t lock;
} SharedData;

void* increment(void* arg) {
    SharedData* data = (SharedData*)arg;

    // Lock the mutex before updating the counter
    pthread_mutex_lock(&data->lock);
    int i;
    for (i = 0; i < NUM_INCREMENTS; ++i) {
        data->counter += 1;  // Protected section
    }
    // Unlock the mutex after updating
    pthread_mutex_unlock(&data->lock);

    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;
    SharedData data;
    data.counter = 0;
    pthread_mutex_init(&data.lock, NULL);  // Initializing mutex

    pthread_create(&thread1, NULL, increment, &data);
    pthread_create(&thread2, NULL, increment, &data);

    // Join threads
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // result
    printf("Expected counter value: %d\n", 2 * NUM_INCREMENTS);
    printf("Final counter value: %d\n", data.counter);

    // Destroy the mutex
    pthread_mutex_destroy(&data.lock);

    return 0;
}

