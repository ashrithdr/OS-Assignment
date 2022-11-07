# Writing a Multi-Threaded Program

## Question:

Write a multithreaded program that outputs prime numbers. This program should work as follows: The user will run the program and will
enter a number on the command line. The program will then create a
separate thread that outputs all the prime numbers less than or equal to
the number entered by the user.

The Program will report the output as follows:

![Project Image](https://github.com/ashrithdr/OS-Assignment/blob/main/Question%202-4.23/output%20images/final_program_run.png)

## Approach

### The C Program: ![threads.c](https://github.com/ashrithdr/OS-Assignment/blob/main/Question%202-4.23/Problem4_23.c)
Taking the input from user via local variable n and asking the user to enter the number.

```
        int n; 

        printf("\n Input Thread \n");
	    printf("Enter a number: ");
	    scanf("%d",&n);
```

### Functions and Data Types involved in thread making:

### 1. **Data Type *p_thread***:
```
        pthread_t th1;
```
pthread_t is a data type for thread th1
### **2. Function *pthread_create():***
```
        int pthread_create(pthread_t *__restrict__thread,const pthread_attr_t *__restrict__attr, void *(*start_routine)(void *), void *restrict arg);
```
For Line 21 in ![threads.c](https://github.com/ashrithdr/OS-Assignment/blob/main/Question%202-4.23/Problem4_23.c) 
```
        pthread_create(&th1,NULL,thread1,&n);
```
Here in the above 3 **pthread_create()** statements:

  1. First argument is a pointer to pthread_t type that is the data type for threads as per "pthreads.h" library which have already been defined as t1, t2, t3 respectively.
  2. Second argument is attr pointing to a pthread_attr_t structure whose contents are used at thread creation time to determine attributes for the new thread. This structure is initialized using pthread_attr_init() function.In the above case attr is given as NULL, as we want the thread is created with default attributes.
  3. Third argument is a pointer to the start_routine of a thread that is the function invoked on the thread creation. In our case the functions invoked are *thread_average*, *thread_minimum*, *thread_maximum* respectively.
  4. Fourth Argument is *the sole* argument passed to start_routine() when invoked during thread creation. In our case it is NULL i.e. no arg is passed to our start_routine.
  5. On success, these functions return 0; on error, they return a nonzero error number.

### **3. Function *pthread_join():***
```
        int pthread_join(pthread_t thread, void **retval);
```

The pthread_join() function waits for the thread specified by
thread to terminate.  If that thread has already terminated, then
pthread_join() returns immediately.  The thread specified by
thread must be joinable.

For Line 24 in ![threads.c](https://github.com/ashrithdr/OS-Assignment/blob/main/Question%202-4.23/Problem4_23.c)
```
        pthread_join(th1,NULL);
```
###  **4. User defined function \**thread1(void *arg)****

We define the function *\*thread1 as follows:*

```

	void *thread1(void *arg)
    {
	
	    printf("\n Output Thread \n");
	    printf("\nThe prime numbers less than or equal to the input number is \n");

	    int *number=(int *) arg;
	    int n,b,i;
	
	    for(b=2;b<=*number;b++)
	    {
 	 	    i=2;
 		    while(b%i!=0)
  		    {
  			    i++;
  		    }
 		    if(i==b)
  		    {
			    printf("%d\n",b) ;
		    }
  	    }

    }        
```
## References:


* https://github.com/Ayush3910/OS-Project
* https://www.geeksforgeeks.org/multithreading-c-2/
* https://man7.org/linux/man-pages/man3/pthread_join.3.html
* https://www.ibm.com/docs/en/zos/2.3.0?topic=functions-pthread-create-create-thread#ptcrea
