# Collatz Conjecture Problem
The Collatz conjecture is one of the most famous unsolved problems in mathematics. The conjecture asks whether repeating two simple arithmetic operations will eventually transform every positive integer into 1.

## Question 
The Collatz conjecture concerns what happens when we take any positive integer n and apply the following algorithm:
n =
{ n∕2, if n is even
3 × n + 1, if n is odd
The conjecture states that when this algorithm is continually applied,
all positive integers will eventually reach 1. For example, if n = 35, the
sequence is
35, 106, 53, 160, 80, 40, 20, 10, 5, 16, 8, 4, 2, 1
Write a C program using the fork() system call that generates this
sequence in the child process. The starting number will be provided
from the command line. For example, if 8 is passed as a parameter on
the command line, the child process will output 8, 4, 2, 1. Because the
parent and child processes have their own copies of the data, it will be
necessary for the child to output the sequence. Have the parent invoke
the wait() call to wait for the child process to complete before exiting
the program. Perform necessary error checking to ensure that a positive
integer is passed on the command line

The program will report as follows:

![Project Image](https://github.com/ashrithdr/OS-Assignment/blob/main/Question%201-3.21/output%20images/final_program_run.png)
## Getting Started
Need to have a Linux based OS.
### Install Components
```
sudo apt-get update
sudo apt-get upgrade  
sudo apt install build-essential
```
### Running the Program
Make sure your terminal is open in the directory where Problem3_21.c file is  
```
gcc Problem3_21.c -o Problem3_21.exe
./Problem3_21.exe
```
## Approach
### The C Program: [process.c](Problem3_21.c)

###  **1. User defined function *int Collatz (int num)***
We define the function *int Collatz(int num)* as follows:
```
int Collatz (int num) 
{
  
    // Declaring the variable
    int count = 0;
  
    // Checking the required error condition
    if (num <= 0)
    { 
        printf ("<Starting Value> should be positive integer");
        return 0;
    }

    // While loop repeats time 10000  
    //to execute the program 
    while (count != 10000)
    {

        // when input number is equal to 1
        if (num == 1)
	    {
            // display the number
	        printf ("%i ", num);

            // return the zero value
	        return 0;
        }
        // when number is even
	    else if (num % 2 == 0)
        {   
        // display the even number
        printf ("%i ", num);

        // half the number to even
	    num /= 2;
	}
    // when number is odd
	else 
	{
        // display the number
	    printf ("%i ", num);
      
        // number verified it is odd condition  
	    num = num * 3 + 1;
	}
    // increment the counter value
	count++;
  }

  return 0;
}
```
###  **2. Data Type *pid_t***:
The pid_t data type represents process IDs. You can get the process ID of a process by calling getpid. The function getppid returns the process ID of the parent of the current process (this is also known as the parent process ID).

```
            pid_t pid;
```
Creating local variable pid which stores the process id of each processes

###  **3. Function *fork()***:
Fork system call is used for creating a new process, which is called child process, which runs concurrently with the process that makes the fork() call (parent process). 
It takes no parameters and returns an integer value.  
Different return types of fork() are
1)	Positive value- returned to parent, and the value is the  process id of the newly created child process.
2)	Zero- return to the child process.
3)	Negative – child process creation was not successful  
  
Lets see what happens when 2 fork() calls are called to get a better understanding  
<pre>
fork ();   // Line 1
fork ();   // Line 2

       P1       // There will be 1 child process 
    /     \     // created by line 1.
  P1      P2    // There will be 2 child processes
 /  \    /  \   //  created by line 2
P1  P3  P2  P4  // There will be 4 child processes 
</pre>
###  **4. Function *wait()***:
A call to wait() blocks the calling process until one of its child processes exits or a signal is received. After child process terminates, parent continues its execution after wait system call instruction.  

## References:
* https://www.geeksforgeeks.org/fork-system-call/
* https://www.geeksforgeeks.org/wait-system-call-c/
* https://www.includehelp.com/c/process-identification-pid_t-data-type.aspx








 
