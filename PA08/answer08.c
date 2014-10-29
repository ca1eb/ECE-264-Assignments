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

List * List_traverse(List * head)
{
  //LOCAL DECLARATIONS
  List * ptr = head;

  //EXECUTABLE STATEMENTS
  while (ptr != NULL)
    {
      if (ptr->next == NULL)
	{
	  return ptr;
	}
    }

  return ptr;
}

void insert(List * dest, List * src)
{
  //LOCAL DECLARATIONS
  
  //EXECUTABLE STATEMENTS
  dest = List_traverse(dest);

  while (src != NULL)
    {
      dest->next = src;
      src = src->next;
    }
  
  dest->next = NULL;

  return;
}
List * List_merge(List * lhs, List * rhs, int (*compar)(const char *, const char*))
{
  //LOCAL DECLARATIONS
  //int bigger = compar(lhs->str, rhs->str);
  List * new = NULL;
  //new->next = NULL;
  //List * tmp = malloc(sizeof(List));
  //new->next = NULL;

  //EXECUTABLE STATEMENTS
  while (lhs != NULL && rhs != NULL)
    {
      int bigger = compar(lhs->str,rhs->str);

      if (bigger <= 0)
	{
	  tmp = lhs;
	  lhs = lhs->next;
	  tmp->next = NULL;
	  insert(new,tmp);
	}
      else
	{
	  tmp = rhs;
	  tmp->next = NULL;
	  rhs = rhs->next;
	  insert(new,tmp);
	}
    }

  if (lhs != NULL)
    {
      insert(new,lhs);
    }
  else if (rhs != NULL)
    {
      insert(new,rhs);
    }

  return new;
}

List * List_sort(List * list, int (*compar)(const char *, const char*))
{
  return list;
}
