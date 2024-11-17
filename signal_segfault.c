/**
 * @file signal_segfault.c
 * @brief Program that dereferences a null pointer causing a segmentation fault
 */

/**
 * Modified by: Braydon H
 * 
 * Brief summary of modifications:
 * Added method to handle the signal and declared the signal to the method.
 */


#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handle_NULL() {
    printf("Segmentation fault was received\n");
    exit(1);
}

int main (int argc, char* argv[]) {
    // Declare a null pointer
    int* i = NULL;
    // Declare signal 
    signal(SIGSEGV, handle_NULL);

    // Dereference the null pointer
    printf("The value of i is: %d\n", *i);

    // Return to exit the program
    return 0;
}