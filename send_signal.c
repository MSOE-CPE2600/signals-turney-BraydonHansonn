/**
 * File: send_signal.c
 * Modified by: Braydon H
 * 
 * Brief summary of program:
 * Program gets the user PID to send a random number to be recieved in recv_signal.c file
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>   


int main (int argc, char* argv[]) {
    pid_t pid = getpid();
    if(argc == 2) {
        pid = atoi(argv[1]);
    }

    printf("Receiver process PID: %d\n", pid);


    srand(time(NULL));
    int value = rand() % 100;
    printf("Random Value: %d\n", value);

    union sigval sendValue;
    sendValue.sival_int = value;

    // Declare sigaction
    sigqueue(pid, SIGUSR1, sendValue);


    printf("User signal %d received\nSIGUSR1 sival_int: %d\n", pid, value);
    return 0;
}