#ifndef MEMORY_MANAGER_H_
#define MEMORY_MANAGER_H_

// Pre-defined block size of 20MB
// 1 MB = 1024*1024 bytes, so 20MB = 20*1024*1024 bytes
// an int is 4 bytes. So our block size is = (20*1024*1024)/4 = 5242880
// divide by 2 again since we are using a struct to represent memory blocks

#define BLOCK_SIZE 2621440 // represents 20MB in mem_block-type
// We need to divide that number up into a static array 

// global memory block with size 20 MB
// simulated as an array of integers
// by default empty, so all values are 0
// when memory gets occupied, all occupied cells of the array set to 1
//int MemoryBlock[BLOCK_SIZE]= {};

// struct representing the memory block
// by default here everything init to 0
// size of this struct = 8 bytes = (2*sizeof(int))
typedef struct mem_block{ unsigned int isAllocated=0, Process_ID=0; }mem_block;

class MemoryManager
{
public:	
	// functions, similar format as a real malloc() call
	void* my_malloc(unsigned int size, unsigned int PID);
	void* my_free(void* ptr, unsigned int size);
private:
	MemoryManager();
	~MemoryManager();

};

#endif

