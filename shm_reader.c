#include<stdio.h>  
#include<stdlib.h>  
#include<unistd.h>  
#include<sys/shm.h>  
#include<string.h>  
int main()  
{  

	void *data;  
	char buff[100];  
	int shmid;  
	
	
	 
	shmid=shmget((key_t)1234, 1024, 0666);  
	
	
	printf("Key of shared memory is %d\n",shmid);  
	
	data=shmat(shmid,NULL,0); //process attached to shared memory segment  
	
	printf("Process attached at %p\n",data);  
	
	printf("Data read from shared memory is : %s\n",(char *)data);  

	getchar();//let's wait here
	 // detach from shared memory
	 shmdt(data);
          
 	 // destroy the shared memory
	 shmctl(shmid, IPC_RMID, NULL);
}  
