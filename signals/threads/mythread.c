#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Function that each thread will execute
void* print_message_function(void *ptr) {
    char *message;
    message = (char *) ptr;
    
    // Print the message and the thread ID
    printf("%s Thread ID: %ld\n", message, pthread_self());

    // return thread exit status, optional
    pthread_exit((void*)message);
}

// Main function
int main() {
    pthread_t thread1, thread2;
    char *message1 = "Thread 1 finishing";
    char *message2 = "Thread 2 finishing";
    void *returnStatus1;
    void *returnStatus2;

    // first thread
    if(pthread_create(&thread1, NULL, print_message_function, (void*) message1)) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }

    // second thread
    if(pthread_create(&thread2, NULL, print_message_function, (void*) message2)) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }

    // Wait for the threads to finish and capture the exit status
    if (pthread_join(thread1, &returnStatus1)) {
        fprintf(stderr, "Error joining thread\n");
        return 1;
    }

    if (pthread_join(thread2, &returnStatus2)) {
        fprintf(stderr, "Error joining thread\n");
        return 1;
    }


    printf("Thread 1 exited with status: %s\n", (char*) returnStatus1);
    printf("Thread 2 exited with status: %s\n", (char*) returnStatus2);

    return 0;
}

