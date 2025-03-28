#include <stdio.h>
#include <pthread.h>

int main() {
    pthread_attr_t attr;
    size_t stack_size;
    int detach_state;
    int policy;
    struct sched_param param;
   int scope;

    pthread_attr_init(&attr);  // Initialize attributes

//stack size
    pthread_attr_getstacksize(&attr, &stack_size);  // Get stack size

    printf("Default stack size: %zu bytes\n", stack_size);

    //detached state
    pthread_attr_getdetachstate(&attr, &detach_state);

    if (detach_state == PTHREAD_CREATE_JOINABLE)
        printf("Default detach state: JOINABLE\n");
    else
        printf("Default detach state: DETACHED\n");

   //scheduling policy
  pthread_attr_getschedpolicy(&attr, &policy);

    if (policy == SCHED_FIFO)
        printf("Default scheduling policy: SCHED_FIFO\n");
    else if (policy == SCHED_RR)
        printf("Default scheduling policy: SCHED_RR\n");
    else
        printf("Default scheduling policy: SCHED_OTHER\n");


  //thread priority
   pthread_attr_getschedparam(&attr, &param);

    printf("Default thread priority: %d\n", param.sched_priority);

   //scope
   pthread_attr_getscope(&attr, &scope);

    if (scope == PTHREAD_SCOPE_SYSTEM)
        printf("Default scope: SYSTEM (competes with all system threads)\n");
    else
        printf("Default scope: PROCESS (competes only with same process threads)\n");


    pthread_attr_destroy(&attr);  // Destroy attributes
    return 0;
}






