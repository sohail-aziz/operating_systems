#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100000000  // Large array size

int main() {
    int *arr = (int *)malloc(ARRAY_SIZE * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Initialize the array with random numbers
    srand(time(NULL));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 100;
    }

    clock_t start = clock();  // Start time

    // Single process sum calculation
    long long sum = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        sum += arr[i];
    }

    clock_t end = clock();  // End time
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Single Process Sum: %lld\n", sum);
    printf("Time Taken: %f seconds\n", time_taken);

    free(arr);
    return 0;
}

