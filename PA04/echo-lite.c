#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * * argv)
{
  //LOCAL DECLARATIONS
  int ind;

  //LOCAL DECLARATIONS
  if (argc > 1)
    {
      for (ind = 1; ind < argc; ind++)
	{
	  printf("%s ", argv[ind]);
	}
    }
  printf("\n");

  return EXIT_SUCCESS;
}
