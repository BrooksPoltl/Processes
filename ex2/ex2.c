// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    FILE * f;
    f = fopen("text.txt","a+");
    fseek(f,0, SEEK_SET);
    char data[100];
    pid_t pid = fork();
    fwrite("hi", 1, sizeof("hi"), f);
    if(pid == 0){
        fseek(f,0, SEEK_SET);
        printf("I am the child: %d\n", (int) getpid());
        fread(data,20,1,f);
        printf("the child content is: %s\n", data);
    }
    else if (pid > 0){
        printf("I am the parent: %d\n", (int) getpid());
        fseek(f,0, SEEK_SET);
        fread(data,20,1,f);
        printf("the parent content is: %s\n", data);
    }
    fclose(f);
    return 0;
}
