/**
 * File: signal_alarm.c
 * Modified by: Braydon H
 * 
 * Brief summary of program:
 * 
 */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Signal handler for SIGINT - prints a message and exits
 */
void handle_signal() {
    printf("Signal Received\n");
    exit(1);
}

int main() {
    int seconds = 5;

    // Register for the signal
    signal(SIGALRM, handle_signal);
    // Wait until a signal is received
    while(1) {
        // wait 5 seconds
        for(int i = 1; i <= seconds ; i++) {
            printf("%d...\n", i);
            sleep(1);
        }
        printf("Alarm\n"); 
        // create the alarm signal
        alarm(1);
    }

    return 0;
}