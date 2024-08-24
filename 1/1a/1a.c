// Chirag Date MT2024034
// Question: Create a soft link file using the `symlink` system call

#include <unistd.h> 
#include <stdio.h>  

void main(int argc, char *argv[])
{

    char *filePath;     
    char *softLinkPath; 

    int status; 

    if (argc != 3)
        printf("Enter File path and Symbolic Link File path as arguments to the program\n");
    else
    {
        filePath = argv[1];
        softLinkPath = argv[2];

        status = symlink(filePath, softLinkPath);

        if (status == -1)
            perror("Error while creating soft link!");
        else
            printf("Successfully created a soft link.\n");
    }
}

/* chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/1/1a$ gcc 1a.c -o 1a.out
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/1/1a$ ./1a.out temp.txt linka1
Successfully created a soft link.
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/Assignments/1/1a$ */
