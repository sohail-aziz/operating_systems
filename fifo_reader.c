#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int main(){

int fd;
char *fifoPath = "/home/sohailaziz/os-lab/myfifo";
char buffer[128];

fd = open(fifoPath, O_RDONLY);
if (fd == -1) {
    printf("unable to open fifo myfifo\n");
    exit(1);
}

read(fd, buffer, sizeof(buffer)); // Read data from the FIFO into buffer
printf("myfifo: Received: %s\n", buffer);
close(fd); // Close the FIFO

 //unlink 
 
 unlink(fifoPath);

}
