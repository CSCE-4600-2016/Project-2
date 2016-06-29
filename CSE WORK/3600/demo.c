#include <stdio.h>

int main (int argc, char *argv[])
{
  int count;
  if (argc > 1)
    {
	printf("%s\n",argv[2]);
      for (count = 3; count < argc; count++)
	{
	  printf(" -%s\n",  argv[count]);
	}
    }
  else
    {
      printf("The command had no other arguments.\n");
    }

  return 0;
}
