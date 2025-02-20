#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc,char* argv[]){

  if(argc!=3){
   printf("Usage: %s srcfile destfile\n",argv[0]);
   return -1;
  }
  
  int srcFd,destFd;
  char buf[1024];
  ssize_t bytesRead,bytesWritten;
   
  srcFd=open(argv[1],O_RDONLY);
  if(srcFd==-1){
   printf("error openning file\n");
   return -1;
  }
  
  destFd=open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,0644);
  
  if(destFd==-1){
   printf("Error opening file for writing\n");
   close(srcFd);
   return -1;
  }
  
  //read in the loop
  while((bytesRead=read(srcFd,buf,sizeof(buf))>0){
     printf("bytesRead=%ld\n",bytesRead);
     //printf("text read=%s\n",buf);
     
     bytesWritten=write(destFd,buf,sizeof(buf));
     
     printf("bytes written =%ld\n",bytesWritten);  
   
   
   
  }
  
  //close the file descriptors
  close(srcFd);
  close(destFd);
 
  

return 0;
}
