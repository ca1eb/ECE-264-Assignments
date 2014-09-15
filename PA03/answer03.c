#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char * strcat_ex(char * * dest, int * n, const char * src)
{
  //LOCAL DECLARATIONS

  //EXECUTABLE STATEMENTS
  if (*dest == NULL || (*n < (strlen(*dest) + strlen(src) + 1))) 
    {
      char * buffer= malloc(1 + 2 * (strlen(*dest) + strlen(src)) * sizeof(char));
      *n = (1 + 2 * (strlen(*dest) + strlen(src)));
      strcpy(buffer,*dest);
      free(*dest);
      *dest = &buffer[0];
      strcat(*dest,src);
    }
  else
    {
      strcat(*dest,src);
    }

  return (char*) dest;
}

