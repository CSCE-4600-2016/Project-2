#include <stdio.h>
#include <unistd.h>

void inc_n(int *n)
{
   /* increment n to 100 */
   while(++(*n) < 1000000000);
}

int main (int argc, char *argv[]){
	
	int pid;
	int x = 0, y = 0;
	
	pid = fork();
	
	if (pid == 0){
		printf("x: %d, y: %d\n", x, y);
		inc_n(&y);
		printf("y increment finished\n");
		printf("y:  %d\n", y);
	}
	else{
		printf("x: %d, y: %d\n", x, y);
		inc_n(&x);
		printf("x increment finished\n");
		printf("x:  %d\n", x);
	}
	
	
	return 1;
}

