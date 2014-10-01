#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * * argv)
{
  //LOCAL DECLARATIONS
  int ind;
  //int helpSwitch = 0;
  char stdinCH;
  char stdoutCH;

  //EXECUTABLE STATEMENTS
  for (ind = 1; ind < argc; ind++)
    {
      if (strcmp(argv[ind],"--help") == 0)
	{
	  printf("Usage: cat-lite [--help] [FILE]...\n");
	  printf("With no FILE, or when FILE is -, read standard input.\n\n");
	  printf("Examples:\n");
	  printf("  cat-lite README   Print the file README to standard output.\n");
	  printf("  cat-lite f - g    Print f's contents, then standard input,\n");
	  printf("                    then g's contents.\n");
	  printf("  cat-lite          Copy standard input to standard output.\n");
	  //helpSwitch++;
	  return EXIT_SUCCESS;
	}
    }     
  
  for (ind = 1; ind < argc; ind++)
    {
      if (strcmp(argv[ind],"-") == 0)
	{
	  FILE * inputFile = stdin;
	  while (feof(inputFile) == 0)
	    {
	      stdinCH = fgetc(inputFile);
	      if (feof(inputFile) == 0)
		{
		  printf("%c", stdinCH);
		}
	    }
	}
      else if (fopen(argv[ind], "r") == NULL)
	{
	  fprintf(stderr, "cat cannot open %s\n", argv[ind]);

	  return EXIT_FAILURE;
	}
      else
	{
	  FILE * currentFile = fopen(argv[ind],"r");
	  while (feof(currentFile) == 0)
	    {
	      stdoutCH = fgetc(currentFile);
	      if (feof(currentFile) == 0)
		{
		  fprintf(stdout, "%c", stdoutCH);
		}
	      //printf("%c",stdoutCH);
	    }
	  fclose(currentFile);
	}
    }
  

  return EXIT_SUCCESS;
}

