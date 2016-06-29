#include <stdio.h>
#include <unistd.h>


int main(int argc, char *argv[] )
{
	int child_pid; 
	int count1 = 0, count2 = 0;

	printf("Before it forks!\n " );


	sleep(5);


	child_pid = fork();

	if (child_pid == 0)
	{

		printf("\nThis is a child process.\n " );
		while(count1 < 10)
		{
			printf("Child process: %d\n", count1);
			sleep(1);
			count1++;
		}

	}
	else
	{
		 printf("\nThis is a parent process.\n " );
                 while(count2 < 10)
                 {
                        printf("Parent process: %d\n", count2);
                        sleep(1);
                        count2++;
                 }
	}

	return 0;
}
