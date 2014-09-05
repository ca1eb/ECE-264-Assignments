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
  char * location;
  int length = (int) my_strlen(str);
  
  //EXECUTABLE STATEMENTS
  if (ch == 0)
    {
      location = "''";      
    }
  else 
    {
      for (counter = 0; counter <= length; counter++)
	{
	  if (str[counter] == (char) ch)
	    {
	      return (char *) &str[counter];
	    }
	  else 
	    {
	      location = "(null)";
            }	
	}
    }
  
  return location;   
}

char * my_strrchr(const char * str, int ch)
{ 
  //LOCAL DECLARATIONS
  int counter;
  char * location;
  int length = (int) my_strlen(str);

  //EXECUTABLE STATEMENTS
  if (ch == 0)
    {
      location = "''";
    }
  else
    {
      for (counter = length; counter >= 0 ; counter--)
	{
          if (str[counter] == (char) ch)
            {
              return (char *) &str[counter];
            }
          else
            {
              location = "(null)";
            }
        }
    }

  return location;
}

char * my_strstr(const char * haystack, const char * needle)
{
  //LOCAL DECLARATIONS
  int counter;
  int needCount = 0;
  char * find = "(null)";
  int needLen = (int) my_strlen(needle);
  int hayLen = (int) my_strlen(haystack);
  int potential;
  int sameLetters = 0;
  
  //EXECUTABLE STATEMENTS                                                                                                     
  if (needLen == 0)
    {
      find = (char *) &haystack[0];
    }
  else 
    {
      for (counter = 0; counter < hayLen; counter++)
    	{
    	  if (haystack[counter] == needle[0])
    	    {
    	      potential = counter;
    	      while (haystack[potential] == needle[needCount])
		{
		  potential++;
		  needCount++;
		  sameLetters++;
		}
	      if (sameLetters == needLen)
		{
		  return (char *) &haystack[counter];
		}
	    }
        }
    }

  return find;
}

/*char * my_strcpy(char * dest, const char * src)
{
  //LOCAL DECLARATIONS                                                   
  int srcLen = (int) my_strlen(src);
  int counter;

  //EXECUTABLE STATEMENTS                                                           
  for (counter = 0; counter < srcLen; counter++) 
    {
      dest[counter] = src[counter];
    }

  return dest;
}
/*  
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
}*/
