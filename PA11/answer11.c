#include<string.h>
#include<stdio.h>
#include <stdlib.h>
#include"answer11.h"

/**
* Create a new, properly intialized HuffNode
*/
HuffNode * HuffNode_create(int value)
{
  HuffNode * node = malloc(sizeof(HuffNode));
  node->value = value;
  node->right = NULL;
  node->left = NULL;

  return node;
}

/**
* Destroy a tree, including all sub-children. Must handle NULL values safely.
*/
void HuffNode_destroy(HuffNode * tree)
{
  if (tree == NULL)
    {
      return;
    }
  
  HuffNode_destroy(tree->right);
  HuffNode_destroy(tree->left);

  free(tree);

  return;
}

StackNode * StackNode_create(HuffNode * tree)
{
  StackNode * node = malloc(sizeof(StackNode));
  node->tree = tree;
  node->next = NULL;

  return node;
}

/**
* Returns a pointer to a new empty stack struct
*/
Stack * Stack_create()
{
  Stack * stack = malloc(sizeof(Stack));
  stack->head = NULL;

  return stack;
}

void Head_destroy(StackNode * head)
{
  if (head == NULL)
    {
      return;
    }
  
  Head_destroy(head->next);
  HuffNode_destroy(head->tree);
  free(head);
}

/**
* Frees all memory associated with the stack.
* Don't forget that you must free the entire contained linked-list.
* Also, you must safely do nothing if stack == NULL.
*/
void Stack_destroy(Stack * stack)
{
  if (stack == NULL)
    {
      return;
    }
  
  Head_destroy(stack->head);
  free(stack);
  
  return;
}

/**
* Returns TRUE (something other than zero) if the stack is empty.
*/
int Stack_isEmpty(Stack * stack)
{
  if (stack == NULL)
    {
      return 0;
    }
  
  return 1;
}

/**
* Pop the front (top) 'value' (i.e. Huffman tree) from the stack.
*
* More precisely, this function must do three things:
* (1) Save the value (i.e. Huffman tree) of the head node of the stack's list
* (2) Remove the head node of the stack's list, freeing it.
* (3) Return the value (i.e. Huffman tree) saved in (1).
*/
HuffNode * Stack_popFront(Stack * stack)
{
  HuffNode * node = stack->head->tree;
  //printf("%d\n", node->value);
  StackNode * tmp = stack->head;
  stack->head = stack->head->next;
  tmp->next = NULL;
  free(tmp);
  //tmp->next = NULL;
  //Head_destroy(tmp);

  return node;
}

/**
* Push a 'value' (i.e. Huffman tree) onto the front (top) of the stack.
*
* More precisely, this function must do two things:
* (1) Create a new StackNode with 'tree' for its tree.
* (2) Push that new StackNode onto the front of the stack's list.
*/
void Stack_pushFront(Stack * stack, HuffNode * tree)
{
  StackNode * node = StackNode_create(tree);
  node->next = stack->head;
  stack->head = node;

  return;
}

// -------------------------------------------------------- Pop Pop combine Push
/**
* This function helps simplify building a Huffman Coding Tree from the header
* information. It takes a stack as input. As a precondition, you can assume
* that the stack has at least two nodes. This function pops the front (top)
* two nodes, combines them into a single node, and pushes the new node back
* onto the stack. See Huffman_Coding.pdf to understand conceptually how this
* should be done.
*/
void Stack_popPopCombinePush(Stack * stack)
{
  HuffNode * tree1 = Stack_popFront(stack);
  HuffNode * tree2 = Stack_popFront(stack);
  
  HuffNode * root = HuffNode_create(tree1->value + tree2->value);

  root->right = tree1;
  root->left = tree2;

  Stack_pushFront(stack, root);

  return;
}

// ---------------------------------------------------- Reading HuffTree headers
/**
* Read a Huffman Coding Tree (in text format) from 'fp'.
*/
HuffNode * HuffTree_readTextHeader(FILE * fp)
{
  Stack * stack = Stack_create();
  int c = fgetc(fp);
  
  while (c != EOF)
    {
      if (c == '1')
	{
	  c = fgetc(fp);
	  HuffNode * tmpHuff = HuffNode_create(c);
	  Stack_pushFront(stack, tmpHuff); 
	}
      else if (c == '0')
	{
	  if (Stack_isEmpty(stack))
	    {
	      if (stack->head->next != NULL)
		{
		  Stack_popPopCombinePush(stack);
		}
	      else 
		{
		  break;
		}
	    }
	}

      c = fgetc(fp);
    }
  

  HuffNode * root = Stack_popFront(stack);
  Stack_destroy(stack);

  return root;
}

int readBit(FILE * fp, unsigned char * bit, unsigned char * whichbit, unsigned char * curbyte)
{
  int ret = 1;
  if ((*whichbit) == 0)
    {
      ret = fread(curbyte, sizeof(unsigned char), 1, fp);
    }
  
  if (ret != 1)
    {
      return -1;
    }
  
  unsigned char temp = (*curbyte) >> (7 - (*whichbit));
  temp = temp & 0X01;
  *whichbit = ((*whichbit) + 1) % 8;
  *bit = temp;
  
  return 1;
}

/**
* Read a Huffman Coding Tree (in binary format) from 'fp'.
* You will need to (conceptually) read a file a bit at a time. See the README
* for hints on how to do this.
*/
HuffNode * HuffTree_readBinaryHeader(FILE * fp)
{
  Stack * stack = Stack_create();
  int done = 0;
  unsigned char whichbit = 0;
  unsigned char curbyte = 0;
  unsigned char onebit = 0;
  //Stack * stack = Stack_create();

  while (done == 0)
    {
      readBit(fp, &onebit, &whichbit, &curbyte);
      
      if (onebit == 1)
	{
	  int bitcount;
	  unsigned char value = 0;

	  for (bitcount = 0; bitcount < 8; bitcount++)
	    {
	      value <<= 1;
	      readBit(fp, &onebit, &whichbit, &curbyte);
	      value |= onebit;
	    }
	  HuffNode * tn = HuffNode_create(value);
	  Stack_pushFront(stack, tn);
	}
      else
	{
	  if (stack == NULL)
	    {
	      printf("Error! Stack should not be NULL\n");
	    }
	  
	  if (stack->head->next == NULL)
	    {
	      done = 1;
	    }
	  else
	    {
	      Stack_popPopCombinePush(stack);
	    }
	}

    }

  HuffNode * root = Stack_popFront(stack);
  Stack_destroy(stack);

  return root;
}
