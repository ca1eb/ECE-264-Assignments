#include<stdio.h>
#include "answer02.h"

//This is a test 
size_t my_strlen(const char * str)
{
  //LOCAL DECLARATIONS
  int charCount = 0;
  

  //EXECUTABLE STATEMENTS
  while (*str != '\0')
    {
      str++;
      charCount++;
    }
  
  return charCount;
}

int my_countchar(const char * str, char ch)
{
  //LOCAL DECLARATIONS
  int myChar = 0;

  //EXECUTABLE STATEMENTS
  while (*str != '\0')
    {
      if (*str == ch)
	{
	  myChar++;
	}
      str++;
    }

  return myChar;
}

char * my_strchr(const char * str, int ch)
{
  //LOCAL DECLARATIONS

  //EXECUTABLE STATEMENTS
  while (*str != '\0' && *str != (char) ch)
    {
      str++;
    }
  
  if (*str == ch)
    {
      return (char *) str;
    }
  else 
    {
      return NULL;
    }     
}

char * my_strrchr(const char * str, int ch)
{ 
  //LOCAL DECLARATIONS
  const char *final = NULL;
  
  //EXECUTABLE STATEMENTS
  if (ch == '\0')
    {
      return my_strchr(str, ch);
    }

  while ((str = my_strchr(str, ch)) != NULL) 
    {
      final = str;
      str++;
    }
     
  return (char *) final;
}

char * my_strstr(const char * haystack, const char * needle)
{
  //LOCAL DECLARATIONS
  int character = (int) needle[0];

  //EXECUTABLE STATEMENTS
  if (character == 0)
    {
      return (char *) haystack;
    }

  return (my_strchr(haystack, character));
}

char * my_strcpy(char * dest, const char * src)
{
  //LOCAL DECLARATIONS                                                   
  int counter;

  //EXECUTABLE STATEMENTS                                              
  for (counter = 0; src[counter] != '\0'; ++counter)
    {
      dest[counter] = src[counter];
    }
  
  dest[counter] = '\0';
  
  return dest;
}
  
char * my_strcat(char * dest, const char * src)
{
  //LOCAL DECLARATIONS                                                                                                                    
  char * placehold = dest;
  
  //EXECUTABLE STATEMENTS
  while (*placehold != '\0')
    {
      placehold++;
    }   
  
  my_strcpy(placehold, src);
  
  return dest;                                                                                                  
}

int my_isspace(int ch)
{
  //LOCAL DECLARATIONS                                                                                                                    
  int white;

  //EXECUTABLE STATEMENTS                                                                                                                 
  if ((ch >= 9 && ch <= 13) || ch == 32)
    {
      white = 1;
    }
  else 
    {
      white = 0;
    }
  
  return white;
}
  
int my_atoi(const char * str)
{
  //LOCAL DECLARATIONS                        
  int negNum = 0;
  int ret = 0;
    
  //EXECUTABLE STATEMENTS
  while (my_isspace(*str) == 1)
    {
      str++;
    }
  if (*str == '-')
    {
      negNum = 1;
      str++;
    }
  while (*str >= '0' && *str <= '9')
    {
      ret = (ret * 10) + (*str - '0');
      str++;
    }
  if (negNum == 1)
    {
      return -ret; 
    }
  else
    {
      return ret;
    }
}

