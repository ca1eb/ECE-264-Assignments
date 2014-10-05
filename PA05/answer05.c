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

void printPart(int *, int, int);
int numLines(int);
void partition(int *, int, int, int, int);
//void partitionAll(int);

void printPart(int * array, int length, int wSwitch)
{
  //LOCAL DECLARATIONS
  int ind;
  
  //EXECUTABLE STATEMENTS
  for (ind = 0; ind < length - 1; ind++)
    {                                                   //code snippet taken from course notes
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
  for (value = 1; value <= left; value++)
    {
      array[ind] = value;
      partition(array, ind + 1, left - value);
    }

  return;
}
/*
int compareINC(int left, int right)
{
  if (left < right)
    {
      return TRUE;
    }
  
  return FALSE;
}

int compareDEC(int left, int right)
{
  if (right < left)
    {
      return TRUE;
    }
  
  return FALSE;
}

//int compareODD

//int compareEVEN

//int compareOE

//int comparePRIME
*/
int main(int argc, char * * argv)
{
  //LOCAL DECLARATIONS
  //int * array = malloc(sizeof(int) * 8);

  //EXECUTABLE STATEMENTS
  //partitionAll(4);

  return EXIT_SUCCESS;
}

void partitionAll(int value)
{
  //LOCAL DECLARATIONS
  int lines = numLines(value);
  int * array = malloc(sizeof(int) * lines);

  //EXECUTABLE STATEMENTS
  partition(array, 0, value);

  return;
}

void partitionIncreasing(int value)
{
  //LOCAL DECLARATIONS                      
  int lines = numLines(value);
  int * array = malloc(sizeof(int) * lines);
  
  //EXECUTABLE STATEMENTS    
  
  partition(array, 0, value);

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
