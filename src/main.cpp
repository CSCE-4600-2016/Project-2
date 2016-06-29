/*
* Group Members: 
* Chad Smith
* Jimmy Yeung
* Asad Waheed 
*/


#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <chrono>
#include <cstdlib>  // error-checking in malloc and free
#include "ProcessSet.h"

using namespace std;

// Globals   
char *MemoryBlock;
static size_t next_index = 0;
const char ast = '*'; // reresents a filled block of memory
string memory;
unsigned int avaliableMemory = 0;

//-------------------------------------------------

size_t my_malloc(size_t sz)
{
	// to simulate the addition allocating memory we append characters to a string.
	// each character, *, represents 1 mb of the total memory block
	// this won't do any error checking, requires user to do the error checking
	memory.append(sz, ast);

	return sz;
}

//-----------------------------------------------------

void my_free(size_t mem)
{
	// erase this amount of "memory" from the allocated string to simulate freeing memory
	memory.erase(0, mem);
}

//-------------------------------------------------------

void sleepNanoSeconds(int sleepTime)
{
	auto sleepStart = chrono::high_resolution_clock::now();
	long sleepedNanoSeconds = 0;
	do
	{
		sleepedNanoSeconds = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - sleepStart).count();
	}
	while(sleepedNanoSeconds < sleepTime);
}

/*  Part one:
 *  Assuming that the combined memory requirement of all 64 processes is less than 20 MB, use the system calls malloc()
 *  and free() to dynamically allocate and de-allocate memory to your processes. Measure the total system time that is
 *  required to simulate the execution of your 64 processes.
 */
chrono::nanoseconds memorySimulatePartOne(ProcessSet process_set) {
	
	cout << "Starting Memory Simulateion Part One" << endl;
	
	void *allocatedMemory = nullptr;
	
	chrono::nanoseconds totalTime = chrono::nanoseconds::zero();
	// Run all 64 processes
	while(process_set.GetNumberProcesses() > 0) {
		auto memAllocStart = chrono::high_resolution_clock::now();
		
		Process currentProcess = process_set.FirstProcess();
		
		cout << "Starting process " << currentProcess.processId << endl;
		
		int memoryFootPrintForCurrentProcess = currentProcess.memoryFootprint;
		
		auto totalTimeStart = chrono::high_resolution_clock::now();
		// Allocate memory for this process
		allocatedMemory = malloc(memoryFootPrintForCurrentProcess * 1024); // The memory footprint is in KB
		
		if (allocatedMemory == nullptr) {
			cout << "Error allocating memory for process with process ID " << currentProcess.processId << endl ;
			return totalTime;
		}
		// free the memory for this process
		free(allocatedMemory);
		auto totalTimeEnd = chrono::high_resolution_clock::now();
		totalTime += (totalTimeEnd - totalTimeStart);

		// Delete the process since we are done.
		process_set.PopProcess();
		
	}
	
	cout << "Total program execution time: " << totalTime.count() << " nanoseconds" << endl;
	
	return totalTime;
}

// Part 2
/*
*   We simulate malloc and free using custom functions
*   my_malloc and my_free to dynamically allocate and
*   deallocate memory to each process. 
*
*/

chrono::nanoseconds memorySimulatePartTwo(ProcessSet process_set)
{
	
	cout << "Starting Memory Simulation Part Two" << endl;
	
	
	size_t memorySize = 20 * 1024 * 1024;
	MemoryBlock = static_cast<char *>(malloc(memorySize));

	memory = MemoryBlock;
	memory.clear();
	avaliableMemory = memorySize - memory.length();

	size_t allocatedMemory = 0;
	chrono::nanoseconds totalTime = chrono::nanoseconds::zero();
	// Run all 64 processes
	while(process_set.GetNumberProcesses() > 0) 
	{
		Process currentProcess = process_set.FirstProcess();
		
		cout << "Starting process " << currentProcess.processId << endl;

		auto memoryFootPrintForCurrentProcess = currentProcess.memoryFootprint;
		
		if(memoryFootPrintForCurrentProcess > avaliableMemory)
		{
			cout << "Error, Process will use up all memory avaliable." << endl;
			return totalTime;
		}
		// Allocate memory for this process
		allocatedMemory = my_malloc(memoryFootPrintForCurrentProcess * 1024); // The memory footprint is in Kb

		auto totalTimeStart = chrono::high_resolution_clock::now();
		// free the memory for this process
		my_free(allocatedMemory);
		auto totalTimeEnd = chrono::high_resolution_clock::now();
		totalTime += (totalTimeEnd - totalTimeStart);
		// Delete the process since we are done.
		process_set.PopProcess();

	}
	
	// get the memory ready again;
	free(MemoryBlock);
	memory.clear();
	memory.append(20 * 1024 * 1024, '0');
	return totalTime;
}

// part 3(a) - Using 10% of the memory of all the processes
//(b) Using 50% of the memory of all processes
// for mode pass in either 'a' for part a, or 'b' for part b
chrono::nanoseconds memorySimulatePartThree(ProcessSet process_set, char mode)
{
	vector<Process> currentProcesses;
	queue<Process> waitingProcesses;
	vector<Process> setOfProcesses;
	chrono::nanoseconds totalTime = chrono::nanoseconds::zero();

	float percentage = mode == 'a' ? 0.1 : 0.5;
	size_t totalMemory = (process_set.GetTotalMemory()*1024) * percentage;

	while(process_set.GetNumberProcesses() > 0)
	{
		setOfProcesses.push_back(process_set.FirstProcess());
		process_set.PopProcess();
	}

	MemoryBlock = static_cast<char *>(malloc(totalMemory));

	memory = MemoryBlock;
	memory.clear();
	avaliableMemory = totalMemory - memory.length();

	while(setOfProcesses.size() > 0)
	{
		for (unsigned i = 0; i < setOfProcesses.size(); i++)
		{
			auto process = setOfProcesses[i];
			// find the processes we need to run first
			if(process.memoryFootprint <= avaliableMemory)
			{
				avaliableMemory -= process.memoryFootprint;
				currentProcesses.push_back(process);
				setOfProcesses.erase(setOfProcesses.begin(), setOfProcesses.begin() + i + 1);
			}
			
		}

		cout << "Number Of Processes That Can Run: " << currentProcesses.size() << endl;
		cout << "Number Of Processes That Are Waiting: " << setOfProcesses.size() << endl;
		// the current process that we need to run
		
		for(auto process : currentProcesses)
		{
			size_t allocatedMemory;
			cout << "Starting process " << process.processId << endl;

			auto memoryFootPrintForCurrentProcess = process.memoryFootprint;

			if (memoryFootPrintForCurrentProcess > avaliableMemory)
			{
				cout << "Error, Process will use up all memory avaliable." << endl;
				return totalTime;
			}
			auto totalTimeStart = chrono::high_resolution_clock::now();
			// Allocate memory for this process
			allocatedMemory = my_malloc(memoryFootPrintForCurrentProcess * 1024); // The memory footprint is in Kb
			// free the memory for this process
			my_free(allocatedMemory);
			auto totalTimeEnd = chrono::high_resolution_clock::now();
			totalTime += totalTimeEnd - totalTimeStart;
		}
		currentProcesses.clear();
		memory.clear();	
		avaliableMemory = totalMemory - memory.length();
	}
	free(MemoryBlock);
	memory.clear();

	return totalTime;
}

int main(int argc, char** argv)
{
	// Create a set of processes
	ProcessSet process_set;
	process_set.BuildProcessSet(cin);
	
	// Run Part one
	auto part1Time = memorySimulatePartOne(process_set);
	// Run Part 2
	auto part2Time = memorySimulatePartTwo(process_set);

	// run part 3
	auto part3Time = memorySimulatePartThree(process_set, 'a');
	auto part3bTime = memorySimulatePartThree(process_set, 'b');

	cout << "Part 1 Time: " << part1Time.count() << " nanaseconds" << endl;
	cout << "Part 2 Time: " << part2Time.count() << " nanaseconds" << endl;
	cout << "Part 3a Time: " << part3Time.count() << " nanaseconds" << endl;
	cout << "Part 3b Time: " << part3bTime.count() << " nanaseconds" << endl;
	return 0;
}