#pragma once

#include <fstream>

void initMain(int& width, int& height, int& entranceX, int& entranceY, int& exitX, int& exitY, char*& maze)
{
	//select the maze by changing the name
	std::ifstream mazeFile("mazes/maze_17x23.txt");
	if (mazeFile.is_open())
	{
		mazeFile >> width;
		mazeFile >> height;

		mazeFile >> entranceX;
		mazeFile >> entranceY;

		mazeFile >> exitX;
		mazeFile >> exitY;

		//on heap, giving [size] instead of [width * height] to new get rids of "arithmetic overflow", pretty sure it doesnt make any difference?
		int size = width * height;
		maze = new char[size]; 
		for (int i = 0; i < width * height; i++)
		{
			mazeFile >> maze[i];
		}
		mazeFile.close();
	}
	else
	{
		std::cout << "Unable to open file";
	}
}

void initHelp(int size, char*& maze, char*& mazeHelp)
{
	mazeHelp = new char[size];
	for (int i = 0; i < size; i++)
	{
		if (maze[i] == '#') mazeHelp[i] = '0';
		if (maze[i] == '^') mazeHelp[i] = '1';
	}
}