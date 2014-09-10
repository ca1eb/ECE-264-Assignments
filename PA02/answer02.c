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
  //t counter;
  //ar * location;
  //t length = (int) my_strlen(str);
  
  //EXECUTABLE STATEMENTS
  // if (ch == 0)
  // {
  //  location = "''";      
  //}
  //se 
  //
  //for (counter = 0; counter <= length; counter++)
  //	{
  //	  if (str[counter] == (char) ch)
  //	    {
  //	      location =  (char *) &str[counter];
  //	    }
  //	  else 
  //	    {
  //	      location = "(null)";
  //	      // }	
  //	  //	}
      //  }
  while (*str != (char)ch)
    {
      if (!*str++)
	{
	  return 0;
	}

  return (char *)str;

  
  //return location;   
}

char * my_strrchr(const char * str, int ch)
{ 
  //LOCAL DECLARATIONS
  //int counter;
  //char * location;/
  //int length = (int) my_strlen(str);

  //EXECUTABLE STATEMENTS
  char* ret=0;
  do {
    if( *str == (char) ch)
      {
	ret=str;
      }
  } while (*str++);

  return ret;

//f (ch == 0)
  //{
  //  location = "''";
  // }
  //else
  // {
  /// for (counter = length; counter >= 0 ; counter--)
  //	{
  //    if (str[counter] == (char) ch)
  //      {
  //        return (char *) &str[counter];
  //      }
  //    else
  //      {
  //        location = "(null)";
  //      }
  //  }
  //}

  //turn location;
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

char * my_strcpy(char * dest, const char * src)
{
  //LOCAL DECLARATIONS                                                   
  int index;

  //EXECUTABLE STATEMENTS                                              
  for (index = 0; src[index] != '\0'; ++index)
    {
      dest[index] = src[index];
    }
  dest[index] = '\0';
  
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
  */
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
  int length = (int) my_strlen(str);
  int counter;
  int ret = 0;
  
  //EXECUTABLE STATEMENTS                                                    
  for (counter = 0; counter < length - 1; counter++)
    {
      //printf("%d\n", str[counter]);
      if (my_isspace(str[counter]) == 1)
	{
	  str++;
	}  
    }
  
  while (*str >= '0' && *str <= '9')
    {
      ret = *str;
      printf("%d\n", ret);
      ret *= 10;
      ret += (*str - '0');
      str++;
    }


  return ret;
}

