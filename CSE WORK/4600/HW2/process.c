// Asad Waheed 
// Process.h
// Desc: Implementation file for process.h

#include "process.h"

/* Will use a rand to generate a random number of cycles ranging from 1000 to 11000 */
int createRandomCycles()
{
	int randomizer = mincycles + (rand() % (maxcycles - mincycles));
	return randomizer;
}

/* Generates a random  amount of "memory" ranging from 1KB to 100KB */
int createRandomFootprint()
{
	int max, min, average;
	int belowAvg, aboveAvg;
	int testBelow = rand() % (max - min);
	int testAbove = average + (rand() % (max - average));

	/* Now we need a number both below and above the mean (20)
		We can get one using rand() again in this case			*/

	if((average - min) < testBelow)
	{ return min + (rand() % (average - min)); }
 	else { return testAbove; }
}

/* Process struct generator */
ProcessType *createNewProcess ( int processID, int numOfCycles, int memFootprintSize)
{
	// Using this as a non-OOP type of contructor to set up a new process
	// with the passed function paramters

	ProcessType *process = malloc(sizeof(ProcessType));
	process->processID = processID;
	process->numOfCycles = numOfCycles;
	process->memFootprintSize = memFootprintSize;
}

