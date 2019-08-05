#pragma once

void pickTile(int& playerX, int& playerY, char*& mazeHelp);
void winLose(int playerX, int playerY, int entranceX, int entranceY, int exitX, int exitY, int& condition);

void solveMaze(int width, int height, int entranceX, int entranceY, int exitX, int exitY, char*& mazeHelp)
{
	//player spawns at entrance, changes the tile to 2 (visited)
	int playerX = entranceX - 1, playerY = entranceY - 1;
	mazeHelp[playerX + (playerY * 8)] = '2';

	//if variable: 0 = still searching, 1 = win (standing on the exit), 2 = lost (back to entrance, couldn't find a way)
	int condition = 0;

	while (true)
	{
		pickTile(playerX, playerY, mazeHelp);
		winLose(playerX, playerY, entranceX, entranceY, exitX, exitY, condition);
		if (condition == 1 || condition == 2) break;
	}
}

void pickTile(int& playerX, int& playerY, char*& mazeHelp)
{
	if (mazeHelp[playerX + ((playerY - 1) * 8)] == '1') //up
	{
		playerY--;
		mazeHelp[playerX + (playerY * 8)] = '2';
	}
	else if (mazeHelp[playerX + ((playerY + 1) * 8)] == '1') //down
	{
		playerY++;
		mazeHelp[playerX + (playerY * 8)] = '2';
	}
	else if (mazeHelp[(playerX - 1) + (playerY * 8)] == '1') //left
	{
		playerX--;
		mazeHelp[playerX + (playerY * 8)] = '2';
	}
	else if (mazeHelp[(playerX + 1) + (playerY * 8)] == '1') //right
	{
		playerX++;
		mazeHelp[playerX + (playerY * 8)] = '2';
	}

	else if (mazeHelp[playerX + ((playerY - 1) * 8)] == '2') //up
	{
		mazeHelp[playerX + (playerY * 8)] = '0';
		playerY--;
	}
	else if (mazeHelp[playerX + ((playerY + 1) * 8)] == '2') //down
	{
		mazeHelp[playerX + (playerY * 8)] = '0';
		playerY++;
	}
	else if (mazeHelp[(playerX - 1) + (playerY * 8)] == '2') //left
	{
		mazeHelp[playerX + (playerY * 8)] = '0';
		playerX--;
	}
	else if (mazeHelp[(playerX + 1) + (playerY * 8)] == '2') //right
	{
		mazeHelp[playerX + (playerY * 8)] = '0';
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