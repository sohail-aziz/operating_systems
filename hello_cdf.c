#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

/**
 * calling our own binary/exe cdf using exec
 **/
int main(){


	pid_t pid= fork();

	if(pid==-1) return -1;

	
	if(pid==0){
		//child process

		printf("ChildProcess: pid=%d\n",getpid());
		printf("ChildProcess: calling cdf using exec\n");

		execl("cdf","cdf","-a","-b",NULL);

		printf("Error: this should never be printed\n");

	}else{
		//parent process
	
		printf("ParentProcess: pid=%d\n",getpid());
	
	}



	return 0;
}
