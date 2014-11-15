#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "answer10.h"
/*
typedef struct {
  struct Location * store;
  locationList * next;
} locationList;

typedef struct reviewOffset {
  int fileOff;
  int busID;
  
} revOff;
*/

typedef struct TreeNode {
  struct TreeNode * right;
  struct TreeNode * left;
  struct Business * bus;
  //char * name;
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
/*
struct Location * create_locList(char * name, char * address, char * city, char * state, char * zip, int id, long offset)
{
  struct Location * location = malloc(sizeof(struct Location));
  location->name = name;
  location->address = address;
  location->city = city;
  location->state = state;
  location->zip_code = zip;
  //location->busID = id;
  location->next = NULL;

  return location;
}

void print_locListing(struct Location * list)
{
  printf("%s\n", list->name);
  printf("%d\n", list->busID);
  printf("%s\n", list->address);
  printf("%s\n", list->city);
  printf("%s\n", list->state);
  printf("%s\n", list->zip);

  return;
}
*/

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

int main (int argc, char * * argv)
{
  //LOCAL DECLARATIONS                                                                                                                          
  /*char * name = "GE Aviation";
  char * address = "17498 Dickey Road";
  char * city = "West Lafayette";
  char * state = "Michigan";
  char * zip = "62056";
  int id = 1000;
  long rev = 101;*/

  //EXECUTABLE STATEMENTS                                                                                                                       
  //loc * list = create_locListing(name,address,city,state,zip,id,rev);
  
  //print_locList(list);
  //printf("%p\n", list->next);

  return EXIT_SUCCESS;
}

