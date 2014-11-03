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

void destruct(List * list)
{
  if (list != NULL)
    {
      free(list->str);
      free(list);
    }

  return;
}

void List_destroy(List * list)
{
  //LOCAL DECLARATIONS

  //EXECUTABLE STATEMENTS
  while (list != NULL)
    {
      List * next = list->next;
      destruct(list);
      list = next;
    } 

      return;
}

int List_length(List * list)
{
  //LOCAL DECLARATIONS
  int length = 1;
  
  //EXECUTABLE STATEMENTS
  if (list == NULL)
    {
      return 0;
    }

  while (list->next != NULL)
    {
      length++;
      list = list->next;
    } 

  return length;
}

void List_traverse(List * head)
{
  //LOCAL DECLARATIONS
  
  //EXECUTABLE STATEMENTS
  while (head != NULL)
    {
      if (head->next == NULL)
	{
	  return;
	}
    }

  return;
}

List * concat(List * dest, List * src)
{
  //LOCAL DECLARATIONS

  //EXECUTABLE STATEMENTS
  List * tmp = dest;

  if (dest == NULL)
    {
      return src;
    }

  while (dest->next != NULL)
    {
      dest = dest->next;
    }

  dest->next = src;

  return tmp;
}

List * List_merge(List * lhs, List * rhs, int (*compar)(const char *, const char*))
{
  //LOCAL DECLARATIONS
  List * new = NULL;
  //new->next = NULL;
  List * tmp = NULL;
  
  //EXECUTABLE STATEMENTS
   while (lhs != NULL && rhs != NULL)
    {
      int bigger = compar(lhs->str,rhs->str);

      if (bigger <= 0)
	{
 	  tmp = lhs;
	  lhs = lhs->next;
	  tmp->next = NULL;
	  new = concat(new,tmp);
	}
      else
	{
	  tmp = rhs;
	  rhs = rhs->next;
	  tmp->next = NULL;
	  new = concat(new,tmp);
	}
    }

  if (lhs != NULL)
    {
      new = concat(new,lhs);
    }
  else if (rhs != NULL)
    {
      new = concat(new,rhs);
    }
  
  return new;
}

List * List_sort(List * list, int (*compar)(const char *, const char*))
{
  //LOCAL DECLARATIONS
  int ind;
  int len = List_length(list);
  List * tmp = list;
  List * left = list;
  List * right = NULL;
  
  //EXECUTABLE STATEMENTS
  if (len < 2)
    {
      return list;
    }
  
  for (ind = 1; ind < len/2; ind++)
    {
      tmp = tmp->next;
    }
  
  right = tmp->next;
  tmp->next = NULL;

  left = List_sort(left, compar);
  right = List_sort(right, compar);
  
  List * sorted = List_merge(left, right, compar);
  
  return sorted;
}
