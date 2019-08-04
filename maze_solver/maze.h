#pragma once

#include <fstream>
#include <vector>

void initMaze(int& width, int& height, int& entranceX, int& entranceY, int& exitX, int& exitY, char*& maze)
{
	std::ifstream mazeFile("mazes/maze_8x8.txt");
	if (mazeFile.is_open())
	{
		mazeFile >> width;
		mazeFile >> height;

		mazeFile >> entranceX;
		mazeFile >> entranceY;

		mazeFile >> exitX;
		mazeFile >> exitY;

		int size = width * height;
		//on heap
		maze = new char[size]; 
		for (int i = 0; i < size; i++)
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