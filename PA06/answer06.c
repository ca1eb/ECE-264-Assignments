#include "answer06.h"
#include <stdio.h>

#define NORTH 1
#define EAST 2
#define SOUTH 3
#define WEST 4

int starting_point (char * * maze)
{
  //LOCAL DECLARATIONS
  int ind;
  int stpt = -1;
  
  //EXECUTABLE STATEMENTS
  for (ind = 0, ind <= w, ind++)
    {
      if (maze[0][ind] == ' ')
	{
	  stpt = ind;
	}
    }
	  
  return stpt;
}

void print_directions (char * * maze, int w, int h) 
{
  //LOCAL DECLARATIONS 
  int direction = 

  //EXECUTABLE STATEMENTS
  printf("%c %d\n", direction, n);

  return;
}

int * find_directions (char * * maze, int w, int h, int stpt, int x, int y)
{
  //LOCAL DECLARATIONS
  int * directions[w * h];
  
  //EXECUTABLE STATEMENTS
  if (maze[x + 1][y] == 'X' && x - 1 >= 0) 
    {
      
      find_directions(maze,w,h,x - 1,y); 
    }
  else if (maze[x - 1][y] == 'X' && x + 1 <= h)
    {
      find_directions(maze,w,h,x + 1,y);
    }
  else if (maze[x][y - 1] == 'X' && y - 1 >= 0)
    {
      find_directions(maze,w,h,x,y - 1);
    }
  else if(maze[x][y + 1] == 'X' && y + 1 <= w)
    {
      find_directions(maze,w,h,x,y + 1);
    }
  else 
    {

    }
  
  return;
}


