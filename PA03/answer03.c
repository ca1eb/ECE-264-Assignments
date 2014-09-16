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

char * * explode(const char * str, const char * delims, int * arrLen)
{
  //LOCAL DECLARATIONS
  int counter;
  int ind;
  
  //EXECUTABLE STATEMENTS
  int n = 0;
  for (counter = 0; counter < strlen(str); counter++)
    {
      if (strchr(delims,str[counter]) != NULL)
	{
	  n++;
	}
    }
  printf("%d\n", n);
  char * * strArr = malloc((n + 1) * sizeof(char *));
  
  int arrInd = 0; // this is the next position where we'll create a string
  int last = 0; // 1 + the last index we saw a delimiter. Init to 0.
  for (ind = 0; ind < strlen(str); ind++) //POTENTIAL CHANGE TO <=
    {
      printf("%c\n",str[ind]);
      if (strchr(delims,str[ind]) != NULL)
	{
	  char * tmp = malloc(sizeof(char) * (ind + 1));
	  int bits = ind - last;
	  memcpy(*strArr,tmp,bits);
	  *strArr[arrInd] = *tmp;
	  last = ind + 1;  
	  arrInd++;
	}
    }
  //char * end = malloc(sizeof(char) * (strlen(str) - last));
  //*strArr[n] = *end;
  
  *arrLen = n;

  return strArr;
}
