// consumer.c
#include <stdio.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define SEM_EMPTY_NAME "/sem_empty"
#define SEM_FULL_NAME "/sem_full"

int main() {
    sem_t *sem_empty = sem_open(SEM_EMPTY_NAME, 0);
    sem_t *sem_full = sem_open(SEM_FULL_NAME, 0);

    if (sem_empty == SEM_FAILED || sem_full == SEM_FAILED) {
        perror("Failed to open semaphores");
        return 1;
    }

    for (int i = 0; i < 20; i++) { // Consume 20 items
        sem_wait(sem_full);
        printf("Consumed item %d\n", i);
        sem_post(sem_empty);
        sleep(1); // Simulate time taken to consume an item
    }

    sem_close(sem_empty);
    sem_close(sem_full);
    
    //unlink
   //sem_unlink(SEM_EMPTY_NAME);
    //sem_unlink(SEM_FULL_NAME);

    return 0;
}

