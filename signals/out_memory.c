#include <stdio.h>

int main() {
    int array[5] = {0}; // Allocate an array of 5 integers

    printf("Attempting to write outside the bounds of the array...\n");

    // Deliberately write to an out-of-bounds memory location
    // This will likely cause a segmentation fault (SIGSEGV)
    array[10] = 123; // Index 10 is out of bounds for this array

    // If the program somehow continues, print the value. (Unlikely to be executed)
    printf("array[10] = %d\n", array[10]);

    return 0;
}

