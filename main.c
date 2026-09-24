#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> 
#include <unistd.h>

#define MAX_CHILDREN 8 //Max number of chidren
#define BUFF_SIZE 32 //A big enough buffer that can hold the fibonacci number while writing 

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

int main(int argc, char *argv[]){
    int num_children = argc - 1;  /* number of children is the number of arguments passed minus 1 (the program name) */
    int   i;                    /* shared loop counter */
    int   n[MAX_CHILDREN];         /* the Fibonacci index each child computes */
    pid_t pid[MAX_CHILDREN];       /* PID of each child, so we can wait and print it */
    int   fd[MAX_CHILDREN][2];     /* one pipe per child: fd[i][0]=read, fd[i][1]=write */


    if (num_children < 1 || num_children > MAX_CHILDREN){ 
        printf("Please enter between 1 and 8 numbers");
        return 1;
    }
    

    for (int i = 0; i < num_children; i++){
        n[i] = atoi(argv[i + 1]); // Convert argument to integer

        //create pipe
        if (pipe(fd[i]) == -1) {
            perror("pipe");
            return 1;
        }
        
        pid[i] = fork(); //create child process

        if (pid[i] < 0) {
            printf("Fork failed for child %d\n", i);
            return 1;
        }
        else if (pid == 0){
            char buffer[BUFF_SIZE];
            uint64_t result = fib(n[i]); // Calculate Fibonacci number
            close(fd[i][0]); // Close read end of the pipe in child
            snprintf(buffer, BUFF_SIZE, "%llu", result); // Convert result to string
            write(fd[i][1], buffer, strlen(buffer) + 1); // Write result to pipe
            close(fd[i][1]); // Close write end of the pipe in child
        }
        else {
            close(fd[i][1]); // Close write end of the pipe in parent
        }

        //loop to read results from children
        for(i=0; i < num_children; i++){
            char buffer[BUFF_SIZE];

            waitpid(pid[i], NULL, 0); //wait for child to finish


            read(fd[i][0],buffer,BUFF_SIZE); //read result from pipe
            close(fd[i][0]); //close read end


            printf("Child %d (PID %d): fib(%d) = %s\n", i, pid[i], n[i], buffer);


        }
    
    

    
    return 0;
}     



