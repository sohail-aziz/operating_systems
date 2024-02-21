#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>



int main(){

	pid_t pid= fork();

	if(pid==-1) //fork failed
		return -1;

	if(pid==0){ 
	       	//child process
	
		printf("ChildProcess: my pid=%d\n",getpid());
		printf("running ls -l /usr \n");

		execl("/bin/ls","ls","-l","/usr",NULL);

		printf("this will never be printed if exec is successful\n");

	}else{ 
		//parent process
		printf("ParentProcess: pid=%d",getpid());

	}


	return 0;
}
