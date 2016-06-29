/*

   Program: count.c
   Programmer: Asad Waheed
   Description: A counter function runs a high-count for loop
   and demonstrates synchronization concepts using pthreads

*/

#include <stdio.h>
#include <pthread.h>

#define NUM_LOOPS 20000000
long long sum = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// count function, threaded
void* threadCount( void *arg )

{
        int offset = *(int *) arg;
        for( int i = 0; i < NUM_LOOPS; i++ )
        {
	  // Start  critical section
	  pthread_mutex_lock(&mutex);

          sum += offset;

	  // End critical section
	  pthread_mutex_unlock(&mutex);


        }
        pthread_exit(NULL);
}

// main
int main(void)
{
	// Spawn threads
	  // Create a thread to count up the sum from 1
	  pthread_t id1;
	  int offset1 = 1;
	  pthread_create(&id1, NULL, threadCount, &offset1 );

	  // Create a thread to count down from -1
	  pthread_t id2;
          int offset2 = -1;
          pthread_create(&id2, NULL, threadCount, &offset2 );

	// Wait for threads to finish
	  pthread_join(id1, NULL);
          pthread_join(id2, NULL);



	printf("Sum = %lld\n", sum);
	return 0;
}
