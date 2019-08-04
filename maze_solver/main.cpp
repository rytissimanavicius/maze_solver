#include <iostream>

#include "maze.h"

int main()
{
	int width, height; //size of the maze
	int entranceX, entranceY; //entrance coordinates
	int exitX, exitY; //exit coordinates
	char* maze;

	initMaze(width, height, entranceX, entranceY, exitX, exitY, maze);

	printf("MAZE SIZE: %dx%d\n", width, height);
	printf("START COORDINATES: %d/%d\n", entranceX, entranceY);
	printf("END COORDINATES: %d/%d\n", exitX, exitY);

	for (int i = 0; i < width * height; i++)
	{
		if (i % height == 0) std::cout << std::endl;
		std::cout << " " << maze[i];
	}

	return 0;
}