#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10
int buffer[MAX_ITEMS];
int fill = 0;
int use = 0;

sem_t empty;
sem_t full;
pthread_mutex_t mutex;

void put(int value) {
    buffer[fill] = value;
    fill = (fill + 1) % MAX_ITEMS;
}

int get() {
    int tmp = buffer[use];
    use = (use + 1) % MAX_ITEMS;
    return tmp;
}

void* producer(void* arg) {
    for (int i = 0; i < 100; i++) {
        printf("producer: trying to place an item in the buffer\n");
        
        int emptySlots;
        sem_getvalue(&empty,&emptySlots);
        printf("producer: emptry slots=%d\n",emptySlots);
        
        sem_wait(&empty); // Decrement the semaphore for empty slots
        pthread_mutex_lock(&mutex);
        put(i);
        printf("producer: an item has been placed in the buffer\n");
        pthread_mutex_unlock(&mutex);
        sem_post(&full); // Increment the semaphore for full slots
        
        int fillSlots;
        sem_getvalue(&full,&fillSlots);
        printf("producer: filled slots=%d\n",fillSlots);
    }
    return NULL;
}

void* consumer(void* arg) {
    for (int i = 0; i < 100; i++) {
    	
    	printf("consumer: trying to consume an item from the buffer\n");
    	        
     	int fillSlots;
        sem_getvalue(&full,&fillSlots);
        printf("consumer: filled slots=%d\n",fillSlots);
        
        sem_wait(&full); // Decrement the semaphore for full slots
        pthread_mutex_lock(&mutex);
        int tmp = get();
        pthread_mutex_unlock(&mutex);
        sem_post(&empty); // Increment the semaphore for empty slots
        printf("%d\n", tmp);
        
        int emptySlots;
        sem_getvalue(&empty,&emptySlots);
        printf("consumer: emptry slots=%d\n",emptySlots);
    }
    return NULL;
}

int main() {
    pthread_t p, c;
    sem_init(&empty, 0, MAX_ITEMS); // Initialize semaphore for MAX_ITEMS empty slots
    sem_init(&full, 0, 0); // Initialize semaphore for 0 full slots
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);
    pthread_join(p, NULL);
    pthread_join(c, NULL);

    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);
    return 0;
}

