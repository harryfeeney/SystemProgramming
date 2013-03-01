/*
 * ChildProcs.c
 *
 *  Created on: 25 Feb 2013
 *      Author: harryfeeney
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

void handler(int mysignal){
	pid_t parent_pid = getppid();
	printf("In ChildProcs: The child process %d is about to die, BOOM!!\n\n", getpid());
	if((kill(parent_pid, SIGUSR1)) == -1){
		perror("kill error ");
	}
}

int main(void) {
	signal(SIGINT, SIG_IGN);
	signal(SIGALRM, handler);
	alarm(3);
	sleep(4);
}
