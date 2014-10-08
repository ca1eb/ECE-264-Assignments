#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <math.h>

#define TRUE = 1;
#define FALSE = 0;
#define ALLSWITCH = 1;
#define INCSWITCH  = 2;
#define DECSWITCH = 3;
#define ODDSWITCH = 4;
#define EVENSWITCH = 5;
#define OESWITCH = 6;
#define PRIMESWITCH = 7;

void printPart(int *, int);
void partition(int *, int, int, int);


void printPart(int * array, int length)
{
  //LOCAL DECLARATIONS
  int ind;
  
  //EXECUTABLE STATEMENTS
  printf("= ");
  for (ind = 0; ind < length - 1; ind++)
    {                                                       //code snippet taken from course notes
      printf("%d + ", array[ind]);
    }

  printf("%d\n", array[length - 1]);

  return;
}

void partition(int * array, int ind, int left, int wSwitch)
{
  //LOCAL DECLARATIONS
  int value;


  //EXECUTABLE FUNCTIONS
  if (left == 0)				
    {
      printPart(array, ind);
      
      return;                                            //Code snippet taken from course notes
    }

  if (wSwitch == 1)
    {
      for (value = 1; value <= left; value++)
	{
	  array[ind] = value;
	  partition(array, ind + 1, left - value, 1);
	}
    }
  else if (wSwitch == 5)
    {
      for (value = 2; value <= left; value += 2)
        {
          array[ind] = value;
          partition(array, ind + 1, left - value, 5);
        }
    }
  else if (wSwitch == 4)
    {
      for (value = 1; value <= left; value += 2)
	{
	  array[ind] = value;
	  partition(array, ind + 1, left - value, 4);
	}
    }
  else if (wSwitch == 2)
    {
      int min = 1;
      if (ind != 0)
	{
	  min = array[ind - 1] + 1;
	}
      for (value = min; value <= left; value++)        //NOT DONE INC
        {
	  array[ind] = value;
	  partition(array, ind + 1, left - value, 2);
	}
    }
  else if (wSwitch == 3)
    {
      for (value = 1; value <= left; value++)
	{
	  int valid = 0;
	  if (ind == 0)
	    {
	      valid = 1;
	    }
	  else
	    {
	      if (array[ind - 1] > array[ind])
		{
		  valid = 1;
		}
	    }
	  if (valid == 1)
	    {
	      array[ind] = value;
	      partition(array, ind + 1, left - value, 3);
	    } 
	}
    }
  else if (wSwitch == 6)
    {
      for (value = 1; value <= left; value++)
	{
	  int valid = 0;
	  if (ind == 0)
	    {
	      valid = 1;
	    }
	  else 
	    {
	      valid = (array[ind - 1] % 2) != (value % 2);
	    }
	  if (valid == 1)
	    {
	      array[ind] = value;
	      partition(array, ind + 1, left - value, 6);
	    }
	}
    }

  return;
}

void partitionAll(int value)
{
  //LOCAL DECLARATIONS
  //int lines = numLines(value);
  int * array = malloc(sizeof(int) * value);

  //EXECUTABLE STATEMENTS
  partition(array, 0, value, 1);
  free(array);

  return;
}

void partitionIncreasing(int value)
{
  //LOCAL DECLARATIONS                      
  //int lines = numLines(value);
  int * array = malloc(sizeof(int) * value);
  
  //EXECUTABLE STATEMENTS    
  partition(array, 0, value, 2);
  free(array);

  return;
}

void partitionDecreasing(int value)
{
  //LOCAL DECLARATIONS                                                                                                                     
  int * array = malloc(sizeof(int) * value);                                                                                                 

  //EXECUTABLE STATEMENTS                                                                                                                
  partition(array, 0, value, 3);
  free(array);

  return;
}

void partitionOdd(int value)
{
  //LOCAL DECLARATIONS                                                                                                                    
  int * array = malloc(sizeof(int) * value);

  //EXECUTABLE STATEMENTS                                                                                                                  
  partition(array, 0, value, 4);
  free(array);

  return;
}

void partitionEven(int value)
{
  //LOCAL DECLARATIONS                                                                                                                    
  int * array = malloc(sizeof(int) * value);                                                                                                                              
  //EXECUTABLE STATEMENTS                                                                                                               
  partition(array, 0, value, 5);
  free(array);

  return;
}

void partitionOddAndEven(int value)
{
  //LOCAL DECLARATIONS                                                                                                                  
  int * array = malloc(sizeof(int) * value);
  
  //EXECUTABLE STATEMENTS                                                                                                                 
  partition(array, 0, value, 6);
  free(array);

  return;
}

void partitionPrime(int value)
{
  //LOCAL DECLARATIONS                                                                                                           

  //EXECUTABLE STATEMENTS                                                                                                                 

  return;
}
/*
int main(int argc, char * * argv)
{
  partitionDecreasing(6);
  printf("DONE\n");
  partitionOddAndEven(6);
  printf("DONE\n");
  //partitionEven(6);
  //printf("DONE\n");
  //partitionOdd(5);
  return EXIT_SUCCESS;
}

*/
