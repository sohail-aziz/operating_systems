#include <stdio.h>
#include<unistd.h>
#include<stdbool.h>
#include<sys/wait.h>
#include<stdlib.h>

int  main(){
	int status;

	pid_t pid= fork();
	if(pid== -1) return -1;

	if(pid==0){
	//child process
	  
	   printf("ChildProcess: myId=%d parentId=%d\n",getpid(),getppid());
	   printf("ChildProcess: press any key to exit");
	     
	     char user_input='\0';
	     user_input= getchar();
	     
	     exit(9);


	}else{
	//parent process
	
	      	printf("ParentProcess: waiting: myId=%d parentId=%d\n",getpid(),getppid());

	     printf("ParentProcess: waiting for child to exit");
	     pid_t child_id= wait(&status);

	      if (WIFEXITED(status)) {
                        printf("The process ended with exit(%d).\\n", WEXITSTATUS(status));
                }
                if (WIFSIGNALED(status)) {
                        printf("The process ended with kill -%d.\\n", WTERMSIG(status));
                }
	    // printf("child with id=%d exitted with status=%d\n",child_id,status);


	}

	return 0;

}
