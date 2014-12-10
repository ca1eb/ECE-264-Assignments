#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<math.h>
#include"answer12.h"

typedef struct {
  uint128 start;
  uint128 stop;
  int * prime;
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

  //uint128 max = floor(sqrt(prime->value));
  uint128 i;
   
  if (prime->start < 3)
    {
      prime->start = 3;
    }

  if (prime->start % 2 == 0)
    {
      prime->start = prime->start + 1;
     
    }
  
  for (i = prime->start; i <= prime->stop; i += 2) 
    {
      if (prime->value % i == 0) 
	{
	  *(prime->prime) = 0;
	  pthread_exit(0);
	}
      if (*(prime->prime) == 0)
	{
	  pthread_exit(0);
	}
    }

  pthread_exit(0);
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
  uint128 max = floor(sqrt(value));
  uint128 piece = ((uint128) max + 1 + (uint128) n_threads) / (uint128) n_threads;
  int ind;
  int isPrime = 1;
  Prime * temp = malloc(sizeof(Prime) * n_threads);

  if (value == 2 || value == 3)
    {
      free(temp);
      return TRUE;
    }

  if (value % 2 == 0 || value == 1)
    {
      free(temp);
      return FALSE;
    }

  pthread_t * threads = malloc(sizeof(pthread_t) * n_threads);

  for (ind = 0; ind < n_threads; ind++)
    {
      temp[ind].start = ind * piece;
      temp[ind].stop = (ind + 1) * piece;
      temp[ind].prime = &isPrime;
      temp[ind].value = value;
    } 

  for (ind = 0; ind < n_threads; ind ++)
    {
      pthread_create(&threads[ind], NULL, primalityTest, &temp[ind]);
      //threads++;
    }  
  
  for (ind = 0; ind < n_threads; ind++)
    {
      pthread_join(threads[ind], 0);
    }

  free(temp);
  free(threads);

  if (isPrime == 0)
    {
      return FALSE;
    }

  return TRUE;
}
