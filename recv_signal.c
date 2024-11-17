/**
 * File: recv_signal.c
 * Modified by: Braydon H
 * 
 * Brief summary of program:
 * Program handles a SIGUSR1 signal from a sigaction declaration. Program prints out sival_int value
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handle_signal(int sig, siginfo_t *info, void *ucontext) {
    // Will return a value of 0 for the sival_int when you use kill command
    printf("Recieved signal %d from PID %d with sival_int value: %d\n", sig,info->si_pid, info->si_value.sival_int);
    exit(1);
}

int main (int argc, char* argv[]) {
    struct sigaction sa;
    sa.sa_sigaction = handle_signal;


    // Declare sigaction
    sigaction(SIGUSR1, &sa, NULL);
    printf("Waiting for signals..\n");
    // infinite loop
    while(1) {

    }
    return 0;
}