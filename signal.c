

#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

pid_t childPid;

void myHandler1() {
	printf( "Ot corobki do nk\n");
	kill (getppid (), SIGUSR1);

	}
	
void myHandler2() {
	printf("the best of the best frtk\n");
	kill (childPid, SIGUSR2);

	}

int main(){ 
	signal(SIGUSR1, myHandler1);
	signal(SIGUSR2, myHandler2);
	
	

	pid_t pid = fork();
	if (pid == 0)
    {
		pid_t pidP = getppid();
		while(1) kill (pidP, SIGUSR1);
    }
    else
    {
        childPid = pid;
			while (1)  kill (childPid, SIGUSR2);
    }
	
	return 0;
}
