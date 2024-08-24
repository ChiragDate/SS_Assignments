/* Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10 bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data. */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void main(int argc, char *argv[]){

  char *fileName;
  int fd;
  int status;
  int offset;
  int writeCount;

  if(argc != 2){
    printf("Enter the file name as arguement \n");
  }
  else{
      fileName = argv[1];
      fd = open(fileName, O_RDWR);

      if(fd == -1){
        perror("Error while opening the file \n");
        _exit(1);
      }
      else{
        offset = lseek(fd,10,SEEK_SET); //moving 10 bytes from start
        writeCount = write(fd,"1234567890",10);

        if(writeCount == -1){
          perror("Error while writing the file \n");
          _exit(1);
        }
        else{
          printf("The lseek offset is %d \n",offset);
          
          close(fd);

      }
  }
  }
}

/* chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/10$ touch temp.txt
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/10$ gcc 10.c -o 10.out
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/10$ ./10.out temp.txt
The lseek offset is 10 

*/


