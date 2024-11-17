/**
 * @file signal_handler.c
 * @brief Sets a signal handler for SIGINT, the handler prints a message and then quits
 */

/**
 * Modified by: Braydon H.
 * 
 * Brief summary of modifications: Commented exit(1) for experimental purposes to try 
 * and send a signal to kill the program
 */


#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Signal handler for SIGINT - prints a message and exits
 */
void handle_signal() {
    printf("\nReceived a signal\n");
    //exit(1);
}

int main() {

    // Register for the signal
    signal(SIGINT, handle_signal);

    // Wait until a signal is received
    while(1) {
        printf("Waiting on a signal\n");
        sleep(1);
    }

    return 0;
}