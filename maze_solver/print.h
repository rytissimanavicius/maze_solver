#pragma once

void print(int width, int height, char* array)
{
	for (int i = 0; i < width * height; i++)
	{
		if (i % width == 0) std::cout << std::endl;
		std::cout << " " << array[i];
	}
}

void printPath(int width, int height, char*& maze, char* mazeHelp)
{
	for (int i = 0; i < width * height; i++)
	{
		if (i % width == 0) std::cout << std::endl;

		if (mazeHelp[i] == '2') std::cout << " .";
		else if (maze[i] == '^') std::cout << "  ";
		else std::cout << " " << maze[i];
	}
}