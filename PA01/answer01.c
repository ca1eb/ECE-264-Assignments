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
  int counter;       //loop control variable  
  int increase = 0;  //variable to show whether true or false

  //EXECUTABLE STATEMENTS 
  if (len < 2)
    {
      increase = 1;
    }
  else
     for (counter = 0; counter < len - 1; counter++)
       {
         if (array[counter] <= array[counter + 1])
	   {
	     increase = 1;
	   }
	 else if (array[counter] > array[counter + 1])
	   {
	     increase = 0;
	     counter = len;
	   }
       }

  return increase;
}

int arrayIndexRFind(int needle, const int * haystack, int len)
{
  //LOCAL DECLARATIONS
  int counter;      //loop control variable
  int index = 0;    //index of the needle

  //EXECUTABLE STATEMENTS
  for (counter = 0; counter < len; counter++)
    {
      if (haystack[counter] == needle)
	{
	  index = counter + 1;
	}
      
    }
  if (index == 0)
    {
      index = -1;
    }
  if (index > -1)
    {
      index -= 1;
    }

  return index;
}

int arrayFindSmallest(int * array, int len)
{
  //LOCAL DECLARATIONS
  int counter;               //loop control variable
  int index;                 //index of the minimum
  int minimum = array[0];    //setting minimum
  int current = 0;           //the current array element  

  //EXECUTABLE STATEMENTS
  for (counter = 1; counter < len; counter++)
    {
      array[counter] = current;
	if (current < minimum)
	  {
	    minimum = current;
	    index = counter;
	  }
    }
  if (minimum == array[0])
    {
      index = 0;
    }

  return index;
}
