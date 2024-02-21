#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

/**
 * main with command line arguments
 **/
int main(int argc, char* argv[]){

	printf("total arguments passed= %d\n",argc);

	int i;
	for(i=0;i<argc;i++){
		printf("argument no %d is %s\n",i,argv[i]);
	}



	return 0;
}
