CPSC 457 Assignment 1
Scott Crewson and Siddharth Engineer
Professor: Jalal Kawash
TA: Stephen MacKenzie

This program uses forks to create mutiple processes as well as pipes to communicate between them, each calculating nth Fibonacci number.

The github repo can be found here: https://github.com/scottcrewson06/cpsc457-a1 

How to run:
This code has been written to run on the provided Minix virtual machine. Once putting the files in your shared folder, navigate to the repository and run the following commands on your Minix terminal.

    cc main.c -o main
    ./main 1 2 3 4 5 6 7 8

Keep in mind the integers provided will calculate the first 8 values of the Fibonacci sequence. However the program can take any integer values as long as 1-8 arguments are provided.

