#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"answer09.h"

/*
 * Construct one BusinessNode. You need to allocate memory for this node first.
 *
 * The caller needs to make sure to use strdup(...) for the arguments, do not
 * use strdup(...) inside of this function.
 *
 * stars: the stars of this business
 * name: name of this business
 * address: address of this business
 */
BusinessNode * create_node(char * stars, char * name, char * address)
{
  BusinessNode * node = NULL;
  node = malloc(sizeof(BusinessNode));
  node->name = name;
  node->stars = stars;
  node->address = address;
  node->left = NULL;
  node->right = NULL;

  return node;
}


/* Insert a node into a BST. Primarily used in load_tree_from_file(). Return a
 * pointer to the root of the BST.
 */
BusinessNode * tree_insert(BusinessNode * node, BusinessNode * root)
{
  if (node == NULL)
    {
      return root;
    }

  if (root == NULL)
    {
      return node;
    }
  else 
    {
      if (strcmp(node->name,root->name) > 0)
	{
	  if (root->right == NULL)
	    {
	      root->right = node;
	    }
	  else 
	    {
	      tree_insert(node,root->right);
	    }
	}
      else 
	{
          if (root->left == NULL)
            {
              root->left = node;
            }
          else
            {
              tree_insert(node,root->left);
            }
        }
    }
  
  return root;
}

char * * explode(const char * str, const char * delims, int * arrLen)
{
  int n = 0;
  int ind;
  int counter;
  int arrInd = 0;

  for (ind = 0; ind < strlen(str); ind++)
    {
      if (strchr(delims,str[ind]) != NULL)
        {
          n++;
        }
    }
 
  *arrLen = n + 1;  
  
  int last = 0;
  char * * arr = malloc(sizeof(char*) * (*arrLen));
  
  for (counter = 0; counter < strlen(str); counter++)
    {
      if (strchr(delims,str[counter]) != NULL)
	{
	  arr[arrInd] = malloc(sizeof(char) * (counter - last + 1));
	  arr[arrInd][0] = '\0';
	  memcpy(arr[arrInd],str + last, counter - last);
	  arr[arrInd][counter - last] = '\0';
	  last = counter + 1;
	  arrInd++;
	}
    }
  
  arr[arrInd] = malloc(sizeof(char) * (counter - last + 1));
  arr[arrInd][0] = '\0';
  memcpy(arr[arrInd],str + last, counter - last);
  arr[arrInd][counter - last] = '\0';

  return arr;
}

/* Parse a .tsv file line by line, create a BusinessNode for each entry, and
 * enter that node into a new BST. Return a pointer to the root of the BST.
 *
 * The explode(...) function from PA03 may be useful for breaking up a lines 
 * into seperate fields.   char *fgets(char *s, int size, FILE *stream)
 */
BusinessNode * load_tree_from_file(char * filename)
{
  FILE * fptr = fopen(filename, "r");
  BusinessNode * node = NULL;
  BusinessNode * root = NULL;
  char * str = malloc(sizeof(char) * 2048);
  char * * attributes = NULL;

  if (fptr == NULL)
    {
      free(str);
      return NULL;
    }

  int arrLen = 0;
  
  while (fgets(str, 2048, fptr) != NULL)
    {
      attributes = explode(str, "\t", &arrLen);

      node = create_node(attributes[0], attributes[1], attributes[2]);
      root = tree_insert(node, root);
      
      free(attributes);
    }
  
  fclose(fptr);
  free(str);

  return root;
}



/* Search a BusinessNode BST for the node with the name 'name'. Returns
 * pointer to the node with a match.
 *
 * If there is no match, return NULL.
 */
BusinessNode * tree_search_name(char * name, BusinessNode * root)
{
  if (root == NULL)
    {
      return NULL;
    }

  if (strcmp(root->name,name) == 0)
    {
      return root;
    }
  
  if (strcmp(root->name,name) > 0)
    {
      return tree_search_name(name,root->left);
    }
 
  return tree_search_name(name,root->right);
}

/* Print out a single node: name, address, and stars
 * The format can be similar to this:
 *
 * Country Cafe
 * ============
 * Stars:
 *    3.5
 * Address:
 *    1030 Emerald Ter, Sun Prairie, WI 53590
 *
 * This function is not graded, but it could come in very handful while
 * debugging this assignment.
 */
void print_node(BusinessNode * node)
{
  printf("%s\n", node->name);
  printf("============\n");
  printf("Stars: ");
  printf("%s\n", node->stars);
  printf("Address: ");
  printf("%s\n", node->address);

  return;
}

/* Print the entire tree, starting from the root. Like the print_node(...)
 * function, this is not graded.
 */
void print_tree(BusinessNode * tree)
{
  if (tree == NULL)
    {
      return;
    }
  
  print_tree(tree->left);
  print_tree(tree->right);

  print_node(tree);
  
  return;
}

/* Deallocate all of the memory used by a BusinessNode BST, without memory
 * leaks.
 */
void destroy_tree(BusinessNode * root)
{
  if (root == NULL)
    {
      return;
    }
  
  destroy_tree(root->left);
  destroy_tree(root->right);
  
  free(root->name);
  free(root->address);
  free(root->stars);
  free(root);
  
  return;
}
