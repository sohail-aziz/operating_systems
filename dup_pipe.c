#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>


int main(){

	int pipefd[2];
	pid_t pid;
	
	
	//create a pipe
	if (pipe(pipefd) == -1) { // Create the pipe
        	printf("error createing pipe");
        	exit(EXIT_FAILURE);
    	}
	
	//create a process
	pid= fork();
	
	if(pid==-1){
	  //error creating fork
	  exit(EXIT_FAILURE);
	}
	
	if(pid==0){ 
	//child process
	
	printf("child pid=%d\n",getpid());
	close(pipefd[0]);//close read end
	
	dup2(pipefd[1],STDOUT_FILENO);//redirect standard output to pipe write end
	close(pipefd[1]); //close original pipe write descriptor
	
	execlp("ls","ls","-la",NULL); 
	printf("this should not be printed if exec is successful");
	
	}else{
	 //parent process
	

	close(pipefd[1]);  // Close unused write end
        dup2(pipefd[0], STDIN_FILENO); // Redirect stdin to pipe read end
        close(pipefd[0]);  // Close original pipe read end

        execlp("wc", "wc", "-l", NULL); // Execute wc -l
	printf("this should not be printed if exec is successful");
	 
	 }



return 0;
}
