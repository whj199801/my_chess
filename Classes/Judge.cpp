#include "Judge.h"
#include "HelloWorldScene.h"

//下子后 判断异色棋子各个方向是否可以吃子  以数组judge1[8]存放。未清零
int HelloWorld::judge(int UnChessColor, int x, int y)
{
	//CCLOG("%d",board[2][3]);
	if (board[x + 1][y] == 3 - UnChessColor && x <= 5)
	{
		for (int search = 2; search <= 7 - x; search++)
		{
			if (board[x + search][y] == 0)
				break;
			else
				if (board[x + search][y] == UnChessColor)
					//return 0;
					judge1[0] = 1;
		}
	}
	if (board[x - 1][y] == 3 - UnChessColor && x >= 2)
	{
		for (int search = 2; search <= x; search++)
		{
			if (board[x - search][y] == 0)
				break;
			else
				if (board[x - search][y] == UnChessColor)
					//return 1;
					judge1[1] = 1;
		}
	}

	if (board[x][y + 1] == 3 - UnChessColor && x <= 5)
	{
		for (int search = 2; search <= 7 - y; search++)
		{
			if (board[x][y + search] == 0)
				break;
			else
				if (board[x][y + search] == UnChessColor)
					//return 2;
					judge1[2] = 1;
		}
	}
	if (board[x][y - 1] == 3 - UnChessColor && x >= 2)
	{
		for (int search = 2; search <= y; search++)
		{
			if (board[x][y - search] == 0)
				break;
			else
				if (board[x][y - search] == UnChessColor)
					//return 3;
					judge1[3] = 1;
		}
	}
	if (board[x + 1][y + 1] == 3 - UnChessColor && x <= 5)
	{
		for (int search = 2; search <= 7 - x; search++)
		{
			if (board[x + search][y + search] == 0)
				break;
			else
				if (board[x + search][y + search] == UnChessColor && (x + search) <= 7 && (y + search) <= 7)
					//return 4;
					judge1[4] = 1;
		}
	}

	if (board[x - 1][y - 1] == 3 - UnChessColor && x >= 2)
	{
		for (int search = 2; search <= x; search++)
		{
			if (board[x - search][y - search] == 0)
				break;
			else
				if (board[x - search][y - search] == UnChessColor && (x - search) >= 0 && (y - search) >= 0)
					//return 5;
					judge1[5] = 1;
		}
	}

	if (board[x - 1][y + 1] == 3 - UnChessColor && x <= 5)
	{
		for (int search = 2; search <= x; search++)
		{
			if (board[x - search][y + search] == 0)
				break;
			else
				if (board[x - search][y + search] == UnChessColor && (x - search) >= 0 && (y + search) <= 7)
					//return 6;
					judge1[6] = 1;
		}
	}
	if (board[x + 1][y - 1] == 3 - UnChessColor)
	{
		for (int search = 2; search <= 7 - x; search++)
			if (board[x + search][y - search] == 0)
				break;
			else
				if (board[x + search][y - search] == UnChessColor && (x + search) <= 7 && (y - search) >= 0)
					//return 7;
					judge1[7] = 1;
	}
	//for (int i = 0; i < 8; i++)
		//CCLOG("%d %d", judge1[i], i);
	return -1;

}