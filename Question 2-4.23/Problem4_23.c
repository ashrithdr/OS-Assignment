#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

//Declaring the function to be executed for the thread to be created
void *thread1(void *arg);

void main()
{
	//Input n for the user
	int n;

	printf("\n Input Thread \n");
	printf("Enter a number: ");
	scanf("%d",&n);

	//Declaring a variable, thread id 
	pthread_t th1;

	//Calling pthread function to create a thread
	pthread_create(&th1,NULL,thread1,&n);

	//Call to pthread_join blocks the calling thread until the thread with identifier equal to the first argument terminates 
	pthread_join(th1,NULL);
	
}
void *thread1(void *arg)
{
	//Output
	printf("\n Output Thread \n");
	printf("\nThe prime numbers less than or equal to the input number is \n");

	int *number=(int *) arg;
	int n,b,i;
	
	//For loop printing all the prime numbers less than or equal to input 
	for(b=2;b<=*number;b++)
	{
 	 	i=2;
 		while(b%i!=0)
  		{
  			i++;
  		}
 		if(i==b)
  		{
			//Printing the numbers
			printf("%d\n",b) ;
		}
  	}

}

	