#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"answer03.h"


int main(int argc, char * * argv)
{
  //strcat_ex
  char * str1 = malloc(5 * sizeof(char));
  strcpy(str1,"one");  
  char * str2 = malloc(5 * sizeof(char));
  strcpy(str2,"two");
  int * n;
  int nvalue = 10;
  n = &nvalue;
  strcat_ex(&str1,n,str2);
  printf("%s\n", str1);
  
  //
  char * str3 = malloc(15 * sizeof(char));
  strcpy(str3,"this is three");
  char * str4 = malloc(13 * sizeof(char));
  strcpy(str4,"three i say");
  
  int len;
  char * * strArr = explode("The\nTuring test", " \t\v\n\r\f", &len);
  printf("%s\n %s\n %s\n", strArr[0], strArr[1], strArr[2]);  

  return EXIT_SUCCESS;
}

