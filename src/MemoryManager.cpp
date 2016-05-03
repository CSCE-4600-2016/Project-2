#include "MemoryManager.h"
#include "Process.h"
#include <cstdlib>

MemoryManager::MemoryManager()
{
    
}

MemoryManager::~MemoryManager()
{
	
}

	// call the system’s malloc() function once to request the initial 20MB
	// size block
	mem_block *block = (mem_block *)malloc(BLOCK_SIZE + sizeof(mem_block));

void* MemoryManager::my_malloc(unsigned int size, unsigned int PID)
{

	unsigned int blockIndex = 0, sizeCount = 0, startIndex = 0;

	while(blockIndex < BLOCK_SIZE)
	{
		if(block[blockIndex].isAllocated == 1)
		{
			sizeCount = 0; // reset size count
			blockIndex++;
			startIndex = blockIndex;
		} 
		else
		{
			sizeCount++;
		}
	// stop the loop, we have found a mem. chunk that fits the request size	
	if (sizeCount == size) break; 	

	}

	// Next case: check if the sizeCount is big enough

	if(sizeCount == size)
	{
		// allocate block of memory here by marking allocated as 1
		// and assigning the PID of the process to the cells of the array
		for(blockIndex = startIndex; blockIndex < startIndex + size; blockIndex++)
		{
			block[blockIndex].isAllocated = 1;
			block[blockIndex].Process_ID = PID;
		}
		// Last case: return a pointer to the starting index
		// of the occupied memory block
		return &(block[blockIndex]);
	}
	else
	{
		return 0; 
	}


}

// This can only run once a process is done, 
// which is = to the numberCycles of that process = 0 
void* MemoryManager::my_free(void* ptr, unsigned int size)
{
	unsigned int blockIndex = 0, sizeCount = 0, startIndex = 0;
	if(ptr == 0 || size == 0)
	{
		cout << "\nError: cannot free a slot already empty!"
			 << "\nWarning: request size is 0\n";
		return false;
	}
	if(ptr){ free(ptr); }
}
