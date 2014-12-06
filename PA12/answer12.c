#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include"answer12.h"

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

/**
 * Convert the initial portion of C-string 'str' to an unsigned 128-bit integer
 *
 * This function should be just like atoi(...), except that it returns an 128
 * bit unsigned integer. Return 0 on any error. Don't forget you must skip 
 * white-space.
 *
 * See PA02 for hints on implementing this function.
 */

uint128 alphaTou128(const char * str)
{
  //LOCAL DECLARATIONS                        
  uint128 negNum = 0;
  uint128 ret = 0;
  int ind;

  //EXECUTABLE STATEMENTS
  while (my_isspace(*str) == 1)
    {
      str++;
    }

  for (ind = 0; ind < strlen(str); ind++)
    {
      if (str[ind] == '-')
	{
	  return 0;
	}
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

int intLength(uint128 num)
{
  int counter = 0;

  if (num == 0)
    {
      return 1;
    }

  while (num > 0)
    {
      counter++;
      num = num / 10;
    }

  return counter;
}

/**
 * Return a newly allocated C-string which represents the passed value.
 * The caller is responsible for freeing the allocated string.
 *
 * If you have already implemented alphaTou128(...) (see hint), then you should
 * be able to figure out how to implement u128ToString(...).
 */

char * u128ToString(uint128 value)
{
  int length = intLength(value);
  char * str = malloc(sizeof(char) * (length + 1));
  int ind;
  int current;
  char ch;

  for (ind = length - 1; ind >= 0; ind--)
    {
      current = value % 10;
      ch = (char) current + '0';
      str[ind] = ch;
      value /= 10;
    }
  
  str[length] = '\0';

  return str;
}

/**
 * Test is 'value' is prime.
 * 'n_threads' is the number of threads to create to complete this computation.
 * Return TRUE of FALSE.
 * 
 * LEAK NO MEMORY.
 *
 * Good luck!
 */

int primalityTestParallel(uint128 value, int n_threads)
{
  int nume = 10;

  return nume;
}
