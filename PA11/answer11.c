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
  StackNode * tmp = stack->head;
  tmp->next = NULL;
  stack->head = stack->head->next;
  Head_destroy(tmp);

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
  StackNode * new = malloc(sizeof(StackNode));
  new->tree = tree;
  new->next = stack->head;
  
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
  return;
}

// ---------------------------------------------------- Reading HuffTree headers
/**
* Read a Huffman Coding Tree (in text format) from 'fp'.
*/
HuffNode * HuffTree_readTextHeader(FILE * fp)
{
  HuffNode * new = NULL;

  return new;
}

/**
* Read a Huffman Coding Tree (in binary format) from 'fp'.
* You will need to (conceptually) read a file a bit at a time. See the README
* for hints on how to do this.
*/
HuffNode * HuffTree_readBinaryHeader(FILE * fp)
{
  HuffNode * new = NULL;

  return new;
}
