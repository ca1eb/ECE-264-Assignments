#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char * strcat_ex(char * * dest, int * n, const char * src)
{
  //LOCAL DECLARATIONS
  int destLen;

  //EXECUTABLE STATEMENTS
  if (*dest == NULL || (*n < (strlen(*dest) + strlen(src) + 1))) 
    {
      if (*dest != NULL)
	{
          destLen = strlen(*dest);
	}
      else
	{
	  destLen = 0;
	}

      char * buffer = malloc((1 + 2 * (destLen + strlen(src))) * sizeof(char));
      *n = (1 + 2 * (destLen + strlen(src)));
      *buffer = '\0';
      if (*dest != NULL)
	{
	  strcpy(buffer,*dest);
        }
      free(*dest);
      *dest = &buffer[0];
      strcat(*dest,src);
    }
  else
    {
      strcat(*dest,src);
    }

  return *dest;
}

char * make_substr(const char * s, int start_ind, int len)
{
  //LOCAL DECLARATIONS
  char * buffer = malloc(sizeof(char) * (len + 1));
  s = s + start_ind;
  strncpy(buffer,s,len);
  buffer[len] = '\0';

  return buffer;
}


char * * explode(const char * str, const char * delims, int * arrLen)
{
  int n = 0;
  int ind;
  int counter;
  int arrInd = 0;

  for (ind = 0; ind < strlen(str); ind++)
    {
      if (strchr(delims,str[ind]) != NULL)
        {
          n++;
        }
    }
 
  *arrLen = n + 1;  
  
  int last = 0;
  char * * arr = malloc(sizeof(char*) * (*arrLen));
  
  for (counter = 0; counter < strlen(str); counter++)
    {
      if (strchr(delims,str[counter]) != NULL)
	{
	  arr[arrInd] = malloc(sizeof(char) * (counter - last + 1));
	  arr[arrInd][0] = '\0';
	  memcpy(arr[arrInd],str + last, counter - last);
	  arr[arrInd][counter - last] = '\0';
	  last = counter + 1;
	  arrInd++;
	}
    }
  
  arr[arrInd] = malloc(sizeof(char) * (counter - last + 1));
  arr[arrInd][0] = '\0';
  memcpy(arr[arrInd],str + last, counter - last);
  arr[arrInd][counter - last] = '\0';

  return arr;
}

char * implode(char * * strArr, int len, const char * glue)
{
  //LOCAL DECLARATIONS
  int ind;
  int arrLen;
  int glueLen = strlen(glue);
  char * dest = NULL;

  //EXECUTABLE STATEMENTS
  for (ind = 0; ind < len; ind++)
    {
      arrLen = strlen(strArr[ind]);
      strcat_ex(&dest,&arrLen,strArr[ind]);
      if (ind != (len - 1))
	{
	  strcat_ex(&dest,&glueLen,glue);  // glue doesn't go at the very end
	}
    }

  return dest;
}

int cmpfuncc(const void * a, const void * b)
{  //or *(char*)a
  const char * ptr1 = (const char *) a;
  const char * ptr2 = (const char *) b;
  int val1 = (int) *ptr1;
  int val2 = (int) *ptr2;
  if (val1 < val2)
    {
      return -1;
    }
  if (val1 == val2)
    {
      return 0;
    }

  return 1;
}

int cmpfuncs(const void * a, const void * b)
{
  const char * ptr1 = * (char **) a;
  const char * ptr2 = * (char **) b;

  return (strcmp(ptr1,ptr2));
}

void sortStringArray(char * * arrString, int len)
{
  //LOCAL DECLARATIONS
  
  //EXECUTABLE STATEMENTS
  qsort(arrString,len,sizeof(char*),cmpfuncs);

  return;
}

void sortStringCharacters(char * str)
{
  qsort(str,strlen(str),sizeof(char),cmpfuncc);
  
  return;
}

void destroyStringArray(char * * strArr, int len)
{
  int ind;
  
  for (ind = 0; ind < len; ind++)
    {
      free(strArr[ind]);
    }

  free(strArr);	
  strArr = NULL;

  return;
}


