#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "answer10.h"

typedef struct locList {
  struct locList * next;
  char * name;
  char * address;
  char * city;
  char * state;
  char * zip;
  int busID;
  struct rList * revArr;
} lList;

typedef struct revList {
  int numLines;
  long fptr;
} rList;

typedef struct TreeNode {
  struct TreeNode * right;
  struct TreeNode * left;
  struct locList * bus;
} TN;

struct YelpDataBST {
  FILE * revFile;
  FILE * busFile;
  struct TreeNode * root;
}; 

/* You define this struct in your answerXX.c file. There are different ways
* you might choose to structure it. This object is probably NOT the root
* node of the tree, although it might be an attribute of this object.
*/

rList * create_revList(int numLines, long fptr)
{
  rList * list = malloc(sizeof(rList));
  list->numLines = numLines;
  list->fptr = fptr;

  return list;
}

lList * create_locList(char * name, char * address, char * city, char * state, char * zip, char * id)
{
  lList * location = malloc(sizeof(lList));
  location->name = strdup(name);
  location->address = strdup(address);
  location->city = strdup(city);
  location->state = strdup(state);
  location->zip = strdup(zip);
  location->busID = atoi(id);
  location->revArr = NULL;
  //location->revArr = reviews;
  location->next = NULL;

  return location;
}

void print_locListing(lList * list)
{
  printf("%s\n", list->name);
  printf("%d\n", list->busID);
  printf("%s\n", list->address);
  printf("%s\n", list->city);
  printf("%s\n", list->state);
  printf("%s\n", list->zip);
  //printf("%s\n", list->rev

  return;
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

TN * tree_insert(TN * node, TN * root)
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
      if (strcmp((node->bus)->name,(root->bus)->name) > 0)
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
TN * create_node(lList * bus)
{
  TN * node = NULL;
  node = malloc(sizeof(TN));
  node->right = NULL;
  node->left = NULL;
  node->bus = bus;

  return node;
}

TN * create_tree(char * filename)
{
  FILE * fptr = fopen(filename, "r");
  TN * node = NULL;
  TN * root = NULL;
  //lList * head = NULL;
  lList * list = NULL;
  char * str = malloc(sizeof(char) * 2048);
  char * * attributes = NULL;
  int tmp = -1;

  if (fptr == NULL)
    {
      free(str);
      return NULL;
    }

  int arrLen = 0;
  
  while (fgets(str, 2048, fptr) != NULL)
    {
      attributes = explode(str, "\t", &arrLen);
      list = create_locList(attributes[1], attributes[2], attributes[3], attributes[4], attributes[5], attributes[0]);
      tmp = list->busID;

      while (list->busID == tmp)
	{
	  fgets(str,2048,fptr);
	  attributes = explode(str, "\t", &arrLen);
	  list->next = create_locList(attributes[1], attributes[2], attributes[3], attributes[4], attributes[5], attributes[0]);
	}

      node = create_node(list);
      root = tree_insert(node, root);
      
      free(attributes);
    }
  
  fclose(fptr);
  free(str);

  return root;
}

struct YelpDataBST* create_business_bst(const char* businesses_path, const char* reviews_path)
{
  struct YelpDataBST * var = NULL;

  return var; 
}
/* This function reads the two files and creates an index that can be used
* to search the data and quickly retrieve the reviews. You must *not* store
* all of the review text in memory. Your structure should store the file
* offsets where the review text can be found.
*
* businesses_path - path to the businesses.tsv file provided for this assignment.
* reviews_path - path to the businesses.tsv file provided for this assignment.
* When running on ecegrid, you can pass the following:
* /home/shay/a/ece264p0/share/yelp_data/businesses.tsv
* /home/shay/a/ece264p0/share/yelp_data/reviews.tsv
*
* DO NOT COPY THOSE FILES TO YOUR HOME DIRECTORY. PLEASE ACCESS THEM USING
* THOSE PATHS. THESE ARE LARGE FILES AND WE DO NOT WANT TO FILL THE DISK
* WITH MULTIPLE COPIES OF THEM.
*/

struct Business* get_business_reviews(struct YelpDataBST* bst, char* name, char* state, char* zip_code)
{
  struct Business * var = NULL;

  return var;
}
/* get_reviews(..) should return a pointer to a Business struct object
* on the heap. That object will include links to the individual locations.
* For example, if "McDonald's" is the business, then there would be thousands
* of locations. Each Location struct object in turn contains links to
* reviews of that location.
*
* bst - the object returned by create_business_bst(..)
* name - name of the business to search for (e.g., "McDonald's"); search is
* case insensitive.
* state - two-letter (uppercase) state code to filter locations by, or NULL
* to include all states.
* zip_code - five digit ZIP code to filter locations by, or NULL to include
* all ZIP codes.
*
* Locations must be sorted by state >> city >> address.
*
* Reviews must be sorted by star rating (descending) >> text of review.
*
* Matching of names, cities, and states must be case-insensitive. You
* may use functions from strings.h for that, if you wish.
*/

void destroy_business_bst(struct YelpDataBST* bst)
{
  return;
}
/* Deallocate all memory allocated by the object returned
* by create_business_bst(..) and close the files. */

void destroy_business_result(struct Business* b)
{
  return;
}
/* Deallocate all heap memory tied to an object returned
* by get_business_reviews(..). */

