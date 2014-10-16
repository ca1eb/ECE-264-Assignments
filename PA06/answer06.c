#include "answer06.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NORTH 1
#define EAST 2
#define SOUTH 3
#define WEST 4

int starting_point (char * * maze)
{
  //LOCAL DECLARATIONS
  int ind;
  int stpt = -1;
  int w = strlen(maze[0]);
  
  //EXECUTABLE STATEMENTS
  for (ind = 0; ind <= w; ind++)
    {
      if (maze[0][ind] == ' ')
	{
	  stpt = ind;
	}
    }
	  
  return stpt;
}

void print_path(int movex, int movey, int steps)
{
  //LOCAL DECLARATIONS
  char direction;
 
  //EXECUTABLE STATEMENTS
  if (movex == -1)
    {
      direction = 'N';
    }
  if (movex == 1)
    {
      direction = 'S';
    }
  if (movey == 1)
    {
      direction = 'E';
    }
  if (movey == -1)
    {
      direction = 'W';
    }

  printf("%c %d\n", direction, steps);

  return;
}

void traverse (char * * maze, int w, int h, int x, int y, int movex, int movey)
{
  //LOCAL DECLARATIONS
  int steps = 0;

  //EXECUTABLE STATEMENTS
  while (maze[x][y] != 'X')
    {
      steps++;
      maze[x][y] = 'x';
      x += movex;
      y += movey;
      //maze[x][y] = 'x';
      int right = (maze[x][y + 1] == ' ');
      int left = (maze[x][y - 1] == ' ');
      int up = (maze[x - 1][y] == ' ');
      int down = (maze[x + 1][y] == ' ');

      if (!(right || left || up || down))
	{
	  print_path(movex,movey,steps);
	  print_path(-movex,-movey,steps);
	  
	  return;
	}
      
      if (right + left + up + down >= 1)
	{
	  print_path(movex,movey,steps);

	  if (right)
	    {
	      traverse(maze,w,h,x,y,0,1);
	    }

	  if (left)
	    {
	      traverse(maze,w,h,x,y,0,-1);
	    }

	  if (up)
	    {
	      traverse(maze,w,h,x,y,1,0);
	    }

	  if (down)
	    {
	      traverse(maze,w,h,x,y,-1,0);
	    }
	  
	  print_path(-movex,-movey,steps);
	}	  
    }  
  print_path(-movex,-movey,steps);

  return;
}

void print_directions (char * * maze, int w, int h)
{
  //LOCAL DECLARATIONS                                                                                                                                                                                                                  
  int stpt = starting_point(maze);
  int movex = 1;
  int movey = 0;

  //EXECUTABLE STATEMENTS                                                                                                                                                                                                  
  traverse(maze,w,h,0,stpt,movex,movey);

  return;
}
/*
int main(int argc, char * * argv)
{
  //LOCAL DECLARATIONS
  print_path(-1,0,1);

  //EXECUTABLE STATEMENTS
  

  return EXIT_SUCCESS;
}
  //inside recursive while you keep going
  
  */
