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
  int steps = 1;
  int right;
  int left;
  int up;
  int down;

  //EXECUTABLE STATEMENTS
  while (maze[x][y] != 'X')
    {
      //steps++;
      //maze[x][y] = 'x';
      
      if (x + movex < h && x >= 0)
	{
	  x += movex;
	}

      if (y + movey < w && y >= 0)
	{
	  y += movey;
	}
      
      maze[x][y] = 'x';
      if (y + 1 < w && y + 1 >= 0)
	{
	  right = (maze[x][y + 1] == ' ');
	}
      else 
	{
	  right = 0;
	}
      
      if (y - 1 < w && y - 1 >= 0)
	{
	  left = (maze[x][y - 1] == ' ');
	}
      else
	{
	  left = 0;
	}
      
      if (x - 1 < w && x - 1 >= 0)
	{
	  up = (maze[x - 1][y] == ' ');
	}
      else 
	{
	  up = 0;
	}
      
      if (x + 1 < w && x + 1 >= 0)
	{
	  down = (maze[x + 1][y] == ' ');
	}
      else 
	{
	  down = 0;
	}

      if (!right && !left && !up && !down)
	{
	  //print_path(movex,movey,steps);
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
	      traverse(maze,w,h,x,y,-1,0);
	    }

	  if (down)
	    {
	      traverse(maze,w,h,x,y,1,0);
	    }
	  
	  //print_path(-movex,-movey,steps);
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
  //print_path(-1,0,1);

  //EXECUTABLE STATEMENTS
  

  return EXIT_SUCCESS;
}
  //inside recursive 
  //move(s)
  //for(1-4)  //directions
  //Recurse
  //move(n)
  


int canTraverse(char * * maze, int h, int w, int row, int col, int direction)
{
  //LOCAL DECLARATIONS
  int can = 0;
  int dr = 0;
  int dc = 0;
  
  if (direction == NORTH)
    {
      dr = -1;
      dc = 0;
    }
  else if (direction == SOUTH)
    {
      dr = 1;
      dc = 0;
    }
  else if (direction == WEST)
    {
      dr = 0;
      dc = -1;
    }
  else if (direction == EAST)
    {
      dr = 0;
      dc = 1;
    }

  //EXECUTABLE STATEMENTS
  if (maze[row + dr][col + dc] == ' ' && row + dr >= 0 && row <= h && col + dc >= 0 && col + dc <= w)
    {
      can = 1;
    }
  
  return can;
}

void traverse(char * * maze, int direction, int * row, int * col)
{
  //LOCAL DECLARATIONS
  char dir;
  if (direction == NORTH)
    {
      dir = 'N';
    }
  else if (direction == SOUTH)
    {
      dir = 'S';
    }
  else if (direction == EAST)
    {
      dir = 'E';
    }
  else if (direction == WEST)
    {
      dir = 'W';
    }
 
  //EXECUTABLE STATEMENTS
  printf("%c %d\n", dir, 1);
 
  if (direction == NORTH)
    {
      maze[*row][*col] = '.';
      *row += -1;
      *col += 0;
    }
  else if (direction == SOUTH)
    {
      maze[*row][*col] = '.';
      *row += 1;
      *col += 0;
    }
  else if (direction == EAST)
    {
      maze[*row][*col] = '.';
      *row += 0;
      *col += 1;
    }
  else if (direction == WEST)
    {
      maze[*row][*col] = '.';
      *row += 0;
      *col += -1;
    }

  return;
}

void print_directions (char * * maze, int w, int h)                                                                                          
{                                                                                                                                            
  //LOCAL DECLARATIONS                                                       
  int col = starting_point(maze);                                                                                                   
  int row = 0;                                                                                                                            
                                                                                                                      
  //EXECUTABLE STATEMENTS                                                                                      
  traverse(maze,SOUTH,&row,&col);                                                                                              
                                                                                                                                               
  return;  
} 

void recur(char * * maze, int h, int w, int row, int col)
{
  //LOCAL DECLARATIONS
  //int stpt = starting_point(maze);
  int directions[] = {NORTH, SOUTH, EAST, WEST};
  int ind;

  //EXECUTABLE STATEMENTS
  traverse(maze,SOUTH,&row,&col);
  
  for (ind = 0; ind < 4; ind++)
    {
      if (canTraverse(maze,h,w,row,col,directions[ind]))
	{
	  recur(maze,h,w,row,col);
	}
      
    }
  
  traverse(maze,NORTH,&row,&col);

  return;
}*/
