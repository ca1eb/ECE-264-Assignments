#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <math.h>

void printPart(int *, int);
int numLines(int);

void printPart(int * array, int length)
{
  //LOCAL DECLARATIONS
  int ind;
  
  //EXECUTABLE STATEMENTS
  for (ind = 0; ind < length; ind++)
    {
      printf("%d + ", array[ind]);
    }

  printf("%d\n", array[length - 1]);

  return;
}

int numLines(int value)
{
  //LOCAL DECLARATIONS
  int ind;
  int lines = 1;

  //EXECUTABLE STATEMENTS
  for (ind = 1; ind < (value - 1); ind++)
    {
      lines *= 2;
    }

  return lines;
}


int main(int argc, char * * argv)
{
  //LOCAL DECLARATIONS
  
  //EXECUTABLE STATEMENTS

  return EXIT_SUCCESS;
}

void partitionAll(int value)
{
  //LOCAL DECLARATIONS
  int lines = numLines(value);
  int * valueArr;
  valueArr = malloc(sizeof(int) * lines);

  //EXECUTABLE STATEMENTS
  

  return;
}

void partitionIncreasing(int value)
{
  //LOCAL DECLARATIONS                                                                                        
  //int ind;                                                                                                                                   

  //EXECUTABLE STATEMENTS                                                                                                                


  return;
}

void partitionDecreasing(int value)
{
  //LOCAL DECLARATIONS                                                                                                                     
  //int ind;                                                                                                                             

  //EXECUTABLE STATEMENTS                                                                                                                

  return;
}

void partitionOdd(int value)
{
  //LOCAL DECLARATIONS                                                                                                                    
  //int ind;                                                                                                                                

  //EXECUTABLE STATEMENTS                                                                                                                  

  return;
}

void partitionEven(int value)
{
  //LOCAL DECLARATIONS                                                                                                                    
  //int ind;                                                                                                                              

  //EXECUTABLE STATEMENTS                                                                                                               

  return;
}

void partitionOddAndEven(int value)
{
  //LOCAL DECLARATIONS                                                                                                                    
  //int ind;                                                                                                                                

  //EXECUTABLE STATEMENTS                                                                                                                 

  return;
}

void partitionPrime(int value)
{
  //LOCAL DECLARATIONS                                                                                                                 
  //int ind;                                                                                                                            

  //EXECUTABLE STATEMENTS                                                                                                                 

  return;
}
