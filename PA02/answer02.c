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
      str++;
      if (*str == ch)
	{
	  myChar++;
	}
    }

  return myChar;
}

char * my_strchr(const char * str, int ch)
{
  //LOCAL DECLARATIONS
  int counter;
  char *location;
  int length = (int) my_strlen(str);  
  
  //EXECUTABLE STATEMENTS
  if (ch == 0)
    {
      *location = ' ';
    }
  else 
    {
      for (counter = 0; counter < length; counter++)
	{
	  if (str[counter] == (char) ch)
	    {
	      *location = (char) str[counter];
	    }
	}
    }
      
  return location;
}

char * my_strrchr(const char * str, int ch)
{
  //LOCAL DECLARATIONS

  //EXECUTABLE STATEMENTS
  int location = 0;

  return location;
}

char * my_strstr(const char * haystack, const char * needle)
{
  //LOCAL DECLARATIONS                                                                                                                   
int location = 0;
 

  //EXECUTABLE STATEMENTS                                                                                                                 

  return location;
}
  
char * my_strcpy(char * dest, const char * src)
{
  //LOCAL DECLARATIONS                                                                                                                    
  int location = 0;

  //EXECUTABLE STATEMENTS                                                                                                                 

  return location;
}
  
char * my_strcat(char * dest, const char * src)
{
  //LOCAL DECLARATIONS                                                                                                                    
  int location = 0;

  //EXECUTABLE STATEMENTS                                                                                                                 

  return location;
}
  
int my_isspace(int ch)
{
  //LOCAL DECLARATIONS                                                                                                                    
  int location = 0;

  //EXECUTABLE STATEMENTS                                                                                                                 

  return location;
}
  
int my_atoi(const char * str)
{
  //LOCAL DECLARATIONS                                                                                                                    
  int location = 0;

  //EXECUTABLE STATEMENTS                                                                                                                 

  return location;
}
