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
      if (strcmp(argv[ind],"--help"))
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
      if (fopen(argv[ind], "r") == NULL)
	{
	  fprintf(stderr, "cat cannot open %s\n", argv[ind]);
	}
      else if (strcmp(argv[ind],"-"))
	{
	  FILE * inputFile = stdin;
	  while (feof(inputFile))
	    {
	      stdinCH = fgetc(inputFile);
	      printf("%c", stdinCH);
	    }
	}
      else
	{
	  FILE * currentFile = fopen(argv[ind],"r");
	  while (feof(currentFile))
	    {
	      stdoutCH = fgetc(currentFile);
	      fprintf(stdout, "%c", stdoutCH);
	    }
	  fclose(currentFile);
	}
    }
  

  return EXIT_SUCCESS;
}

