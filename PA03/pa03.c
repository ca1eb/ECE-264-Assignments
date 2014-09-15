#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"answer03.h"


int main(int argc, char * * argv)
{
  //LOCAL DECLARATIONS
  char * str1 = malloc(5 * sizeof(char));
  strcpy(str1,"one");  
  char * str2 = malloc(5 * sizeof(char));
  strcpy(str2,"two");
  int * n;
  int nvalue = 10;
  n = &nvalue;

  //EXECUTABLE STATEMENTS
  strcat_ex(&str1,n,str2);

  printf("%s\n", str1);
  return EXIT_SUCCESS;
}

