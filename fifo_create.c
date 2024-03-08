#include <sys/types.h>
#include <sys/stat.h>
#include<stdio.h>


int main(){
int status;
char *fifoPath = "/home/sohailaziz/os-lab/myfifo";

status = mkfifo(fifoPath, 0666); // Read and write permissions for everyone
if (status == -1) {
    // Handle error
    printf("error creating myfifo\n");
    return -1;
}

printf("myfifo successfully created, with read/write persmission to everyone!\n");
return 0;
}
