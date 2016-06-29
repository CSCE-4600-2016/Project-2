// Asad Waheed 
// Trying out Sweaney's fork program

#include <stdio.h>
#include <stdlib.h>	// assuming this is where the "pid" funcs come from

//constants

#define SIZE 4

int main()
{
	int i,j; 
	pid_t pid;	// The pid_t data type represents process IDs
			// This is the child process 
	
	for( i = 0; i < SIZE; i++)
	{
		pid = fork();
		if( pid == 0 )
		{
		  printf("I'm child process %d, and my parent is %d\n",
			getpid(),getppid());
		  return;
		}
	}
	
	// Condition to verify if a process is the parent process
	if ( pid > 0 )
	{
	  printf("I'm a papa process %d, and my parent is %d\n", 
		getpid(),getppid());
	  printf("\n\n\n");
	}

	return 0; 
}
