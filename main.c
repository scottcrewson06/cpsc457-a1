#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> 

int main (int argc, char *argv[]){

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