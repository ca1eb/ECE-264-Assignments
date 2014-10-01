#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char * * argv)
{
  //LOCAL DECLARATIONS
  int ind;

  //EXECUTABLE STATEMENTS
  for (ind = 1; ind < argc; ind++)
    {
      if (strcmp(argv[ind],"--help") == 0)
        {
          printf("Usage: grep-lite [OPTION]... PATTERN\n");
          printf("Search for PATTERN in standard input. PATTERN is a\n");
	  printf("string. grep-lite will search standard input line by\n");
	  printf("line, and (by default) print out those lines which\n");
	  printf("contain pattern as a substring.\n\n");
          printf("  -v, --invert-match     print non-matching lines\n");
          printf("  -n, --line-number      print line numbers with output\n");
          printf("  -q, --quiet            suppress all output\n\n");
          printf("Exit status is 0 if any line is selected, 1 otherwise;\n");
          printf("if any error occurs, then the exit status is 2.\n");                                                                               
          
	  return 1;
        }
    }
  
  if ((strcmp(argv[1],"-v") == 0 || strcmp(argv[1],"-q") == 0 || strcmp(argv[1],"-n")== 0 || strcmp(argv[1],"--quiet") == 0 || strcmp(argv[1],"--line-number") == 0 || strcmp(argv[1],"--invert-match") == 0) && (argv[argc - 1][0] != '-'))
    {
      FILE * currentFile;
      currentFile = stdin;
      char arr[2000];
      
      while (feof(currentFile) != 0)
	{
	  fgets(arr, 2000, currentFile);
	  if (strstr(arr,argv[argc-1]) == 0)
	    {
	      //fprintf
	    }
	}

      return 1;
    }
  else
    {
      if (argv[argc - 1][0] == '-')
	{
	  fprintf(stderr, "Last argument must not end in a '-'\n");
	}
      else
	{
	  fprintf(stderr, "Command Line Argument Is Not Valid\n");
	}

      return 2;
    }

  return EXIT_SUCCESS;
}
