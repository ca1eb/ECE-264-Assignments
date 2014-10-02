#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TRUE 1
#define FALSE 0

int main(int argc, char * * argv)
{
  //LOCAL DECLARATIONS
  int ind;
  int helpSwitch = FALSE;
  int qSwitch = FALSE;
  int vSwitch = FALSE;
  int nSwitch = FALSE;
  int noSwitch = FALSE;
  int counter = 1;
  int nCase = FALSE;
  int vCase = FALSE;
  int noCase = FALSE;
  int errSwitch = FALSE;

  //EXECUTABLE STATEMENTS
  for (ind = 1; ind < argc - 1; ++ind) 
    {
      if (strcmp(argv[ind], "--help") == 0)
	{
	  helpSwitch = TRUE;
	  //printf("help\n");
	}
      else if (strcmp(argv[ind], "-q") == 0 || strcmp(argv[ind], "--quiet") == 0)
	{
	  qSwitch = TRUE;
	  //printf("q\n");
	}
      else if (strcmp(argv[ind], "-v") == 0 || strcmp(argv[ind], "--invert-match") == 0)
	{
	  vSwitch = TRUE;
	  //printf("v\n");
	}
      else if (strcmp(argv[ind], "-n") == 0 || strcmp(argv[ind],"--line-number") == 0) 
	{
	  nSwitch = TRUE; 
	  //printf("n\n");
	}
    }

  if (!strcmp(argv[1],"-n") && !strcmp(argv[1],"-q") && !strcmp(argv[1],"-v") && !strcmp(argv[1],"--quiet") && !strcmp(argv[1],"--invert-match") && !strcmp(argv[1],"--line-number"))
    {
      errSwitch = TRUE;
    }
  
  if (!nSwitch && !vSwitch && !qSwitch && !helpSwitch)
    {
      noSwitch = TRUE;
      //printf("no\n");
    }
  //printf("%d\n", noSwitch);

  if (errSwitch)
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

  if (helpSwitch)
    {
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
    }
  else if (noSwitch || qSwitch)
    {
      FILE * currentFile;                                                                                                                    
      currentFile = stdin;                                                                                                                
      char arr[2000];  
      while (fgets(arr,2000,currentFile))
	{
	  //fgets(arr,2000,currentFile);  
	  if (strstr(arr,argv[argc - 1]) != NULL)                                                           
	    {        
	      noCase = TRUE;
	      if (!qSwitch)
		{
		  printf("%s", arr);
		}
	    }
	}
      if (noCase)
        {
          return 0;
        }
      else
        {
          return 1;
        }
    }
  else if (vSwitch && nSwitch)
    {
      FILE * currentFile;
      currentFile = stdin;
      char arr[2000];
      while(fgets(arr,2000,currentFile))
        {
          if (strstr(arr,argv[argc - 1]) == NULL)
            {
              vCase = TRUE;
	      if (!qSwitch)
		{
		  printf("%d:%s", counter, arr);
		}
            }
	  counter++;
        }
      if (nCase)
        {
          return 1;
        }
      else
        {
          return 0;
        }
    }
      
  else if (vSwitch)
    {
      FILE * currentFile;
      currentFile = stdin;
      char arr[2000];
      while(fgets(arr,2000,currentFile))
	{
	  if (strstr(arr,argv[argc - 1]) == NULL)
	    {
	      vCase = TRUE;
	      if (!qSwitch)
		{
		  printf("%s",arr);
		}
	    }
	}
      if (nCase)
	{
          return 1;
        }
      else
	{
          return 0;
        }
    }
  else if (nSwitch)
    {
      FILE * currentFile;
      currentFile = stdin;
      char arr[2000];
      while (fgets(arr,2000,currentFile))
        {
          //fgets(arr,2000,currentFile);                                                                                  
          if (strstr(arr,argv[argc - 1]) != NULL)
            {
	      nCase = TRUE;
	      if (!qSwitch)
		{
		  printf("%d:%s", counter, arr);
		}
            }
	  counter++;
	}
      
      if (nCase)
	{
	  return 0;
	}
    }

  return 1;
}
