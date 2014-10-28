#include"answer08.h"
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<libgen.h>

List * List_createNode(const char * str)
{
  //LOCAL DECLARATIONS 
  List * head = NULL;
  head = malloc(sizeof(List));

  //EXECUTABLE STATEMENTS
  head->next = NULL;
  head->str = strdup(str);

  return head;
}

void List_destroy(List * list)
{
  //LOCAL DECLARATIONS

  //EXECUTABLE STATEMENTS
  if (list == NULL)
    {
      return;
    }
  
  List_destroy(list->next);
  free(list);

  return;
}

int List_length(List * list)
{
  //EXECUTABLE STATEMENTS
  int length = 0;
  
  //LOCAL DECLARATIONS
  while (list->next != NULL)
    {
      length++;
      list = list->next;
    } 

  return length;
}

List * List_merge(List * lhs, List * rhs, int (*compar)(const char *, const char*))
{
  return lhs;
}

List * List_sort(List * list, int (*compar)(const char *, const char*))
{
  return list;
}
