#include <stdlib.h>
#include "answer01.h"

int arraySum(int * array, int len)
{
  //LOCAL DECLARATIONS
  int counter;     //loop control variable
  int sum = 0;     //sum of the array elements

  //EXECUTABLE STATEMENTS
  for (counter = 0; counter < len; counter++)
    {
      sum += array[counter];
    }

  return sum;
}

int arrayCountNegative(int * array, int len)
{
  //LOCAL DECALARTIONS
  int counter;      //loop control variable 
  int numNeg = 0;   //number of negative elements in the array 

  //EXECUTABLE STATEMENTS
  for (counter = 0; counter < len; counter++)
    {
      if (array[counter] < 0)
	{
	  numNeg += 1;
	}
    }

  return numNeg;
}

int arrayIsIncreasing(int * array, int len)
{    
  //LOCAL DECLARATIONS
  int counter; 
  int increase = 0;

  //EXECUTABLE STATEMENTS 
  for (counter = 0; counter < num + 1; counter++)
    {
      if (len < 2)
	{
	  increase = 0;
	}
      else if (array[counter] < array[counter + 1])
	{
	  increase = 1;
	}
      else if (array[counter] > array[counter + 1])
	{
	  increase = 0;
	  counter = len;
	}

  return increase;
}

int arrayIndexRFind(int needle, const int * haystack, int len)
{
  return 0;
}

int arrayFindSmallest(int * array, int len)
{
  return 0;
}
