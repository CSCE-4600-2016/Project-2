// Asad Waheed
// Syscalls.txt
// Using a bunch of different system calls in a  CPP program

#include <stdio.h> 	//	streams
#include <unistd.h>	//	many syscalls come from here
#include <signal.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <stdlib.h>

// For references on the syscalls and how they are used, go to
// http://pubs.opengroup.org/onlinepubs/7908799/xsh/unistd.h.html

// quick and dirty way to make exit work on Linux box (i feel so shameful lol)
using namespace std;

// Source: http://www.gnu.org/software/libc/manual/html_node/Kill-Example.html

/* When a SIGUSR1 signal arrives, set this variable. */
volatile sig_atomic_t usr_interrupt = 0;

void synch_signal (int sig)
{
  usr_interrupt = 1;
} // variable "trips" to 1 when signal received

/* The child process executes this function. */
void child_function (void)
{
  /* Perform initialization. */
  printf ("I'm here!!!  My pid is %d.\n", (int) getpid ());

  /* Let parent know you’re done. */
  kill (getppid (), SIGUSR1); // KILL, GETPPID

  /* Continue with execution. */
  puts ("Bye, now....");
  exit (0); // EXIT
}

// Entry point
int main (void)
{
  // Variables we need from headers
  struct sigaction usr_action;
  sigset_t block_mask;
  pid_t child_id;

  /* Establish the signal handler. */
  sigfillset (&block_mask);
  usr_action.sa_handler = synch_signal;
  usr_action.sa_mask = block_mask;
  usr_action.sa_flags = 0;
  sigaction (SIGUSR1, &usr_action, NULL);

  /* Create the child process. */
  child_id = fork ();	// FORK

  // If pid is 0, we know it's a child function by definition
  if (child_id == 0)
    child_function ();          /* Does not return. */

  /* Busy wait for the child to send a signal. */
  while (!usr_interrupt);

  /* Now continue execution. */
  puts ("That's all, folks!");

  // Using execl() to ls files
  // Modifying this source: 
  //http://pubs.opengroup.org/onlinepubs/9699919799/functions/exec.html
  puts("\n\nFiles currently in this directory...");
  int ret;
  ret = execl ("/bin/ls", "ls", "-1", (char *)0);

  return 0;
}

