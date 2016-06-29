// Asad Waheed
// Process.h
// Desc: Contains prototypes for what we are using in the driver program

// macros
#ifndef PROCESS_H
#define PROCESS_H

#include <stdio.h>
#include <stdlib.h> // rand()
#include <time.h>
// First make a struct called process and typedef it for easy reference
// This is how to represent a 3-tuple in C

typedef struct Processes
{
	// Now we add necessary data for it
	unsigned int processID;
	unsigned int numOfCycles;
	unsigned int memFootprintSize;

} ProcessType;

// Constants

#define mincycles 1000
#define maxcycles 11000
#define avgcycles 6000
#define minmemfootprint 1
#define maxmemfootprint 100
#define avgmemfootprint 20
#define minPIDvalue 1000
#define maxPIDvalue 9999

// Functions

/* Will use a rand to generate a random number of cycles ranging from 1000 to 11000 */
int createRandomCycles();

/* Generates a random  amount of "memory" ranging from 20KB to 100KB */
int createRandomFootprint();

/* Process struct generator */
ProcessType *createNewProcess ( int pid, int numCycles, int memFootprint);

#endif
