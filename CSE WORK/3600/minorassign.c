/*
	Minor Assignment 2
	Group 19 
	Asad Waheed 
	Dilip Shah
	9 - 15 - 2015
	This program takes a command line argument and reads a data file


*/


#include <stdio.h>

int main (int argc, char *argv[])
{
  int count; // for loop variable

  if (argc > 1)
    {
	printf("%s\n",argv[2]); // to avoid the 2ndex looping inside for loop
      for (count = 3; count < argc; count++)
	{
	  printf(" -%s\n",  argv[count]); // flags
	}
    }
  else
    {
      printf("The command had no other arguments.\n"); //exception handling
    }

  return 0;
}

