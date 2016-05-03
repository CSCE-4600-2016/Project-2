/*
* Group Members: 
* Chad Smith
* Jimmy Yeung
* Asad Waheed 
*/

#include "ProcessSet.h"
#include "Helpers.h"
//#include "MemoryManager.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <chrono>
#include <pthread.h> // because you asked nicely...
#include <unistd.h> //sbrk and brk

using namespace std;

static unsigned char our_memory[20 * 1024 * 1024]; //reserve 1 MB for malloc
static size_t next_index = 0;

void *my_malloc(size_t sz)
{
    void *mem;

    if(sizeof our_memory - next_index < sz)
        return NULL;

    mem = &our_memory[next_index];
    next_index += sz;
    return mem;
}

void my_free(void *mem)
{
    if(mem)
    {
        sbrk(sizeof((long unsigned int*)mem+1) - sizeof((long unsigned int*)&our_memory[next_index]));
        // test statement
        //cout << "\n> Amount of free memory in block: " << (sizeof(our_memory)/sizeof(*our_memory)) << " bytes" << endl;
    } 
   // else 
   //{
   //     cout << "\nInvalid function parameter!\n";
   // }
}




void sleepNanoSeconds(int sleepTime)
{
    auto sleepStart = chrono::high_resolution_clock::now();
    int sleepedNanoSeconds = 0;
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
int memorySimulatePartOne(ProcessSet process_set) {
    
    cout << "Starting Memory Simulateion Part One" << endl;
    
    
    auto totalTimeStart = chrono::high_resolution_clock::now();
    
    void *allocatedMemory = NULL;
    
    // Run all 64 processes
    while(process_set.GetNumberProcesses() > 0) {
        auto memAllocStart = chrono::high_resolution_clock::now();
        
        Process currentProcess = process_set.FirstProcess();
        
        cout << "Starting process " << currentProcess.processId << endl;
        
        int memoryFootPrintForCurrentProcess = currentProcess.memoryFootprint;
        
        // Allocate memory for this process
        allocatedMemory = malloc(memoryFootPrintForCurrentProcess * 1024); // The memory footprint is in KB
        
        if (allocatedMemory == NULL) {
            cout << "Error allocating memory for process with process ID " << currentProcess.processId << endl ;
            return -2;
        }
        // free the memory for this process
        free(allocatedMemory);
        
        // Delete the process since we are done.
        process_set.PopProcess();
        
//        auto memAllocEnd = chrono::high_resolution_clock::now();
//        long long memAllocTimeSpent = (chrono::duration_cast<chrono::nanoseconds>(memAllocStart - memAllocEnd).count());
//        cout << "Current Process execution time was : " << memAllocTimeSpent << " nanoseconds" << endl;
        
//        // Assume one cycle time will take the cpu 1 milisecond to run
//        if (process_set.GetNumberProcesses() > 0) {
//            // 1000000 = milisecond
//            int sleepTime = 1000000 * currentProcess.numberCycles;
//            sleepNanoSeconds(sleepTime);
//        }
    }
    
    auto totalTimeEnd = chrono::high_resolution_clock::now();
    cout << "Total program execution time: " << (chrono::duration_cast<chrono::nanoseconds>(totalTimeEnd - totalTimeStart).count()) << " nanoseconds" << endl;
    
    return 1;
}

// Part 2
/*
*   We simulate malloc and free using custom functions
*   my_malloc and my_free to dynamically allocate and
*   deallocate memory to each process. 
*
*   TODO: write the remaining part of the free function
*   so far there is a trivial check there, but it needs to be
*   be fixed. For future reference this is my bug at runtime:
-------------------------------------------------------------
Starting Memory Simulation Part Two
Starting process 0
*** Error in `./a.out': free(): invalid pointer: 0x00000000006073e0 ***
--------------------------------------------------------------
*   NOTE: Ignore all work done inside the MemoryManager class functions
*   Abandoning OOP in favor of C-style functions
*/

int memorySimulatePartTwo(ProcessSet process_set) 
{
    
    cout << "Starting Memory Simulation Part Two" << endl;
    
    
    auto totalTimeStart = chrono::high_resolution_clock::now();
    
    void *allocatedMemory = NULL;
    
    // Run all 64 processes
    while(process_set.GetNumberProcesses() > 0) 
    {
        auto memAllocStart = chrono::high_resolution_clock::now();
        
        Process currentProcess = process_set.FirstProcess();
        
        cout << "Starting process " << currentProcess.processId << endl;
        
        int memoryFootPrintForCurrentProcess = currentProcess.memoryFootprint;
        
        // Allocate memory for this process
        allocatedMemory = my_malloc(memoryFootPrintForCurrentProcess * 1024); // The memory footprint is in KB
        
        if (allocatedMemory == NULL) 
        {
            cout << "Error allocating memory for process with process ID " << currentProcess.processId << endl ;
            return -2;
        }
        // free the memory for this process
        my_free(allocatedMemory);
        
        // Delete the process since we are done.
        process_set.PopProcess();

    }
    
    auto totalTimeEnd = chrono::high_resolution_clock::now();
    cout << "Total program execution time: " << (chrono::duration_cast<chrono::nanoseconds>(totalTimeEnd - totalTimeStart).count()) << " nanoseconds" << endl;
    
    return 1;
}

int main(int argc, char** argv)
{
    // Create a set of processes
    ProcessSet process_set;
    process_set.BuildProcessSet(std::cin);
    
    // Run Part one
    memorySimulatePartOne(process_set);
    // Run Part 2
    memorySimulatePartTwo(process_set);
	return 0;
}