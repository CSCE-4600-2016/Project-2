// Asad Waheed
// Timing performance of read() and fread()
// Compiles with g++ on Linux CSE machines

#include <time.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

// Sanity check
// const unsigned long long size = 1000000000;

#define BUFFER_SIZE 1024

int main()
{
		size_t i; // might need this later, if not delete

		// We are gonna read() into this
	  char buffer [BUFFER_SIZE];

 		// Using some of the example provided by pubs.opengroup.org
		// Source: http://pubs.opengroup.org/onlinepubs/009695399/functions/read.html
 		size_t nbytes;
		ssize_t bytes_read;

		// File descriptor
		int fd;

		// set our nbytes equal to the buffer's size
		nbytes = sizeof(buffer);

		// Open the given file and check for invalid state
		fd = open("big.rtf",O_RDWR);
		if(fd == 0)
		{
			puts("Error, file doesn't exist.\nBye!!\n");

		}


		// Timing
    clock_t start = clock();

		// Read the file
    bytes_read = read(fd, buffer, nbytes);


		//Initially needed this to make sure clock worked as expected
		//for(i = 0; i < BUFFER_SIZE; i++ )
		//{
		//	i+=1;
		//}

		printf("EXECUTION @ 56/63");
    clock_t end = clock();

    printf("Elapsed: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
