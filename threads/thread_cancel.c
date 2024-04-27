#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void* cancelableThread(void* arg) {
 

     printf("cancelable threadid=%ld\n",pthread_self());
    // Set this thread to be non-cancelable
    pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
    printf("Cancel disabled\n");
    for (int i = 0; i < 5; i++) {
        printf("Not Cancelable thread counts: %d\n", i);
        sleep(1); // A cancellation point
    }
    
    printf("Cancel enabled\n");
    // Set this thread to be cancelable
    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);
    //PTHREAD_CANCEL_DEFERRED cancel on next cancellation point
    //PTHREAD_CANCEL_ASYNCHRONOUS cancel almost immediately
    
       for (int i = 0; i < 5; i++) {
        printf("Cancelable thread counts: %d\n", i);
        sleep(1); // A cancellation point
    }
    

    printf("Cancelable thread finished normally.\n");
    return NULL;
}

int main() {
    pthread_t thread_id;

    pid_t processId= getpid();
    pthread_t mainThreadId= pthread_self();
    
    printf("process id=%d and threadid=%ld\n",processId,mainThreadId);
    
    pthread_create(&thread_id, NULL, cancelableThread, NULL);
    

    // Attempt to cancel the thread
    printf("Main thread attempting to cancel the thread...\n");
    
    pthread_cancel(thread_id);

    sleep(6);
 
  

  // Join the thread to handle its termination
    void *res;
    if (pthread_join(thread_id, &res) == 0) {
        if (res == PTHREAD_CANCELED)
            printf("Thread was canceled.\n");
        else
            printf("Thread terminated normally.\n");
    }
    printf("Main thread finished.\n");

    return 0;
}

