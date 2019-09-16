#pragma once

void pickTile(int width, int height, float scale, int& playerX, int& playerY, char*& mazeHelp);
void winLose(int playerX, int playerY, int entranceX, int entranceY, int exitX, int exitY, int& condition);

void solveMaze(int width, int height, int entranceX, int entranceY, int exitX, int exitY, char*& mazeHelp)
{
	//player spawns at entrance, changes the tile to 2 (visited)
	int playerX = entranceX - 1, playerY = entranceY - 1;
	mazeHelp[playerX + (playerY * 8)] = '2';

	//if variable: 0 = still searching, 1 = win (standing on the exit), 2 = lost (back to entrance, couldn't find a way)
	int condition = 0;

	//since i work with a 1d array for performance boost finding correct positions in different size mazes required some smart scaling
	float scale = (float)width / (float)height;

	//control this cycle if you want to see every step
	while (true)
	{
		pickTile(width, height, scale, playerX, playerY, mazeHelp);
		winLose(playerX, playerY, entranceX, entranceY, exitX, exitY, condition);
		if (condition == 1 || condition == 2) break;
	}
}

void pickTile(int width, int height, float scale, int& playerX, int& playerY, char*& mazeHelp)
{
	int left1 = (playerX - 1) + ((playerY * height) * scale);
	int right1 = (playerX + 1) + ((playerY * height) * scale);
	int left2 = (playerX - 1) + ((playerY * height) * scale);
	int right2 = (playerX + 1) + ((playerY * height) * scale);

	if (mazeHelp[playerX + ((playerY - 1) * width)] == '1') //up
	{
		playerY--;
		mazeHelp[playerX + (playerY * width)] = '2';
	}
	else if (mazeHelp[playerX + ((playerY + 1) * width)] == '1') //down
	{
		playerY++;
		mazeHelp[playerX + (playerY * width)] = '2';
	}
	else if (mazeHelp[left1] == '1') //left
	{
		playerX--;
		mazeHelp[left1] = '2';
	}
	else if (mazeHelp[right1] == '1') //right
	{
		playerX++;
		mazeHelp[right1] = '2';
	}
	else if (mazeHelp[playerX + ((playerY - 1) * width)] == '2') //up
	{
		mazeHelp[playerX + (playerY * width)] = '0';
		playerY--;
	}
	else if (mazeHelp[playerX + ((playerY + 1) * width)] == '2') //down
	{
		mazeHelp[playerX + (playerY * width)] = '0';
		playerY++;
	}
	else if (mazeHelp[left2] == '2') //left
	{
		mazeHelp[left2 + 1] = '0';
		playerX--;
	}
	else if (mazeHelp[right2] == '2') //right
	{
		mazeHelp[right2 - 1] = '0';
		playerX++;
	}
}

void winLose(int playerX, int playerY, int entranceX, int entranceY, int exitX, int exitY, int& condition)
{
	if (playerX + 1 == exitX && playerY + 1 == exitY)
	{
		std::cout << "\n\nPATH FOUND!\n";
		condition = 1;
	}
	else if (playerX + 1 == entranceX && playerY + 1 == entranceY)
	{
		std::cout << "\n\nPATH COULD NOT BE FOUND!\n";
		condition = 2;
	}
}