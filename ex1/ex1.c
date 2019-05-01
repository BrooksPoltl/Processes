// Write a program that calls `fork()`. Before calling `fork()`, 
//have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). 
//What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    int number;
    pid_t pid = fork();
    if(pid == 0){
        printf("I am the child: %d\n", (int) getpid());
        number = 200;
    }
    else if (pid > 0){
        printf("I am the parent: %d\n", (int) getpid());
        number = 100;
    }
    printf("the number is : %d \n", number);
    return 0;
}
