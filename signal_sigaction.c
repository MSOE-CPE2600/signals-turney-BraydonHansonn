/**
 * File: signal_sigaction.c
 * Modified by: Braydon H
 * 
 * Brief summary of program:
 * Program handles a user signal and prints out the signal pid. 
 * It waits in a infinite loop until signal recieved
 * 
 * Comand: kill -SIGUSR1 (pid)
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handle_signal(int sig, siginfo_t *info, void *ucontext) {
    printf("User signal received\nSIGUSR1 with PID: %d\n", info->si_pid);
    exit(1);
}

int main (int argc, char* argv[]) {
    struct sigaction sa;
    sa.sa_sigaction = handle_signal;


    // Declare sigaction
    sigaction(SIGUSR1, &sa, NULL);

    // infinite loop
    while(1) {

    }
    return 0;
}

