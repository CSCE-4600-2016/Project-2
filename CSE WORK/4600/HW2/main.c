// Asad Waheed
// Main.c
// Desc: the driver program to simulate k-processes distribution

#include "process.h"

int main()
{
	// time_t t; safe to assume I don't need this anymore
	int i, n=100;

 /* Intializes random number generator */
   	// Something wrong with the seed here,not enough time to figure it out, normally I should get a different num everytime I run but I'm not.
	srand(time(NULL));
	int PIDval = (rand() % (maxPIDvalue + 1 - minPIDvalue)) + minPIDvalue;

	// Test, running it a hundred times for new PIDs
	for (i = 0; i < n; i++)
	{
		int PIDval = (rand() % (maxPIDvalue + 1 - minPIDvalue)) + minPIDvalue; // nvm...I'm dumb
		printf("Process ID: %d\n", PIDval);
	}

	// Unable to finish. Needed to create a linked list of processtype structs and implement it here but it didn't happen. I believe my calculation for the distribution
	// is correct.

	return 0;
}

