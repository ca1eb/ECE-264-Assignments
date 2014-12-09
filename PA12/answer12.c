#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<math.h>
#include"answer12.h"

typedef struct {
  int start;
  int stop;
  int prime;
  uint128 value;
} Prime;

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

void * primalityTest(void * structure) 
{
  Prime * prime = (Prime *) structure;

  if (prime->value % 2 == 0 || prime->value == 1)
    {
      prime->prime = 0;
      return NULL;
    }

  if (prime->value == 2 || prime->value == 3)
    {
      prime->prime = 1;
      return NULL;
    }

  //uint128 max = floor(sqrt(prime->value));
  uint128 i;
  for (i = prime->start; i <= prime->stop; i += 2) 
    {
      if (prime->value % i == 0) 
	{
	  prime->prime = 0;
	  return NULL;
	}
    }

  return NULL;
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
  int max = floor(sqrt(value));
  int tot = 0;
  int ind;
  int numInt = 0;
  //Prime * temp = malloc(sizeof(Prime));
  void * voidP = temp;

  pthread_t * threads = malloc(sizeof(pthread_t) * n_threads);

  for (ind = 3; ind <= max; ind += 2)
    {
      tot++;
    }

  numInt = tot / n_threads;

  for (ind = 0; ind < n_threads; ind ++)
    {
      pthread_create(threads, NULL, primalityTest, voidP);
      threads++;
    }  
  
  pthread_join(threads);
  
  return ;
}
