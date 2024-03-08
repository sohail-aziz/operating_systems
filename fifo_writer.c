#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include<stdio.h>


int main(){

int fd;
char *fifoPath = "/home/sohailaziz/os-lab/myfifo";
char *message = "Hello, FIFO!";

fd = open(fifoPath, O_WRONLY);
if (fd == -1) {
    printf("unable to open myfifo\n"); 
       exit(1);
}

write(fd, message, strlen(message)); // Write the message to the FIFO
close(fd); // Close the FIFO

}
