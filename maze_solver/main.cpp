#include <iostream>

#include "initialize.h"
#include "solve.h"
#include "print.h"

int main()
{
	//size of the maze
	int width, height; 
	//entrance coordinates
	int entranceX, entranceY; 
	//exit coordinates
	int exitX, exitY; 

	//dynamic arrays that hold mazes, first one for visual representation and second one for calculations
	char* maze;
	char* mazeHelp;

	//initialize both arrays
	initMain(width, height, entranceX, entranceY, exitX, exitY, maze);
	int size = width * height;
	initHelp(size, maze, mazeHelp);

	//find the exit
	print(width, height, maze);
	solveMaze(width, height, entranceX, entranceY, exitX, exitY, mazeHelp);
	printPath(width, height, maze, mazeHelp);

	return 0;
}