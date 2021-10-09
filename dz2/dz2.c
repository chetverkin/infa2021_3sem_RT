#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

// 

int main()
{
	int N = 3;
	for(int i = 0; i < N; ++i){
		
		pid_t pid = getpid();
		pid_t ppid = getppid();

		pid_t pidf = fork();
		if (pidf == 0){
			printf("I'm from %d, I'm %d\n", ppid, pid);
		} else if(pidf > 0){
			wait(NULL);
			printf("My child is dead %d\n", pidf);
			break;
		}
	}

	return 0;
}
