#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> 
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CHILDREN 8 //Max number of chidren
#define BUFF_SIZE 32 //A big enough buffer that can hold the fibonacci number while writing 

int main(int argc, char *argv[]){
    int num_children = argc - 1;  //number of children is the number of arguments passed minus 1 (the program name)
    

    if (num_children < 1 || num_children > MAX_CHILDREN){ 
        printf("Please enter between 1 and 8 numbers");
        return 1;
    }
    
    //pid_t = pids[num_children];

    

    for (int i = 0; i = num_children; i++)
        //create pipe
        //fork
    
        if (pid < 0){
            printf("Fork Failed");
            return(1);
        }
        else if (pid == 0) { 
            //child process
            
        }
        else { //parent process

        }
    
    return 0;
}     

// Returns the nth Fibonacci number (0-indexed: fib(0)=0, fib(1)=1).
uint64_t fib(int n) {
    if (n < 0) return 0;  // guard against negative input
    if (n < 2) return (uint64_t)n;

    uint64_t prev = 0, curr = 1;
    for (int i = 2; i <= n; i++) {
        uint64_t next = prev + curr;
        prev = curr;
        curr = next;
    }
    return curr;
}

