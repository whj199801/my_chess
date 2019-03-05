#include "Change.h"
#include "HelloWorldScene.h"
#include "Judge.h"
void HelloWorld::change()
{
	if (board[px][py] == 0)
	{
		if (count % 2 == 1)
		{
			turn = 1;
		}
		if (count % 2 == 0)
		{
			turn = 2;
		}
		if (board1[px][py] == 1 &&
			turn == 1)
		{
			chessing(1, px, py);
		}
		else
			if (board1[px][py] == 1 &&
				turn == 2)
			{
				chessing(2, px, py);
			}




		judge(turn, px, py);
		if (//judge(turn, px, py) == 0 
			judge1[0]==1
			&& board[px][py] == turn)
		{
			int search;
			if (px <= 5)
			{
				for (search = 2; search <= 7 - px; search++)
				{
					if (board[px + search][py] == turn)
						break;
				}
				for (int i = search - 1; i >= 0; i--)
				{
					//auto chess = (Sprite*)this->getChildByTag(100 * (px + i) + py);
					//this->removeChild(chess);
					board[px + i][py] = 0;
					chessing(turn, px + i, py);
				}
				count = turn + 1;
			}
		}
		 if (//judge(turn, px, py) == 1
			judge1[1]==1
			&& board[px][py] == turn)
		{
			int search;
			if (px >= 2)
			{
				for (search = 2; search <= px; search++)
				{
					if (board[px - search][py] == turn)
						break;
				}
				for (int i = search - 1; i >= 0; i--)
				{
					//auto chess = (Sprite*)this->getChildByTag(100 * (px - i) + py);
					//this->removeChild(chess);
					board[px - i][py] = 0;
					chessing(turn, px - i, py);
				}
				count = turn + 1;
			}
		}

		 if (//judge(turn, px, py) == 2 
			judge1[2] == 1
			&& board[px][py] == turn)
		{
			int search;
			if (py <= 5)
			{
				for (search = 2; search <= 7 - py; search++)
				{
					if (board[px][py + search] == turn)
						break;
				}
				for (int i = search - 1; i >= 0; i--)
				{
					//auto chess = (Sprite*)this->getChildByTag(100 * px +(py+i));
					//this->removeChild(chess);
					board[px][py + i] = 0;
					chessing(turn, px, py + i);
					count = turn + 1;
				}
			}
		}
		 if (//judge(turn, px, py) == 3 
			judge1[3] == 1
			&& board[px][py] == turn)
		{
			int search;
			if (py >= 2)
			{
				for (search = 2; search <= py; search++)
				{
					if (board[px][py - search] == turn)
						break;
				}
				for (int i = search - 1; i >= 0; i--)
				{
					//auto chess = (Sprite*)this->getChildByTag(100*px +(py-i));
					//this->removeChild(chess);
					board[px][py - i] = 0;
					chessing(turn, px, py - i);
					count = turn + 1;
				}
			}
		}
		 if (//judge(turn, px, py) == 4
			judge1[4] == 1
			&& board[px][py] == turn)
		{
			int search;
			if (px <= 5)
			{
				for (search = 2; search <= 7 - px; search++)
				{
					if (board[px + search][py + search] == turn)
						break;
				}
				for (int i = search - 1; i >= 0; i--)
				{
					//board[px + i][py + i] = 0;
					//auto chess = (Sprite*)this->getChildByTag(100 * (px + i) + py+i);
					//this->removeChild(chess);
					board[px + i][py + i] = 0;
					chessing(turn, px + i, py + i);
					count = turn + 1;
				}
			}
		}
		 if (//judge(turn, px, py) == 5 
			judge1[5] == 1
			&& board[px][py] == turn)
		{
			int search;
			if (px >= 2)
			{
				for (search = 2; search <= px; search++)
				{
					if (board[px - search][py - search] == turn)
						break;
				}
				for (int i = search - 1; i >= 0; i--)
				{
					//board[px - search][py - search] = 0;
					//auto chess = (Sprite*)this->getChildByTag(100 * (px - i) + py-i);
					//this->removeChild(chess);
					board[px - i][py - i] = 0;
					chessing(turn, px - i, py - i);
					count = turn + 1;
				}
			}
		}


		else if (//judge(turn, px, py) == 6 
			judge1[6] == 1
			&& board[px][py] == turn)//6为x-1,y+1
		{
			int search;
			for (search = 2; search <= px; search++)
			{
				if (board[px - search][py + search] == turn)
					break;
			}
			for (int i = search - 1; i >= 0; i--)
			{
				//board[px - search][py - search] = 0;
				//auto chess = (Sprite*)this->getChildByTag(100 * (px - i) + py+i);
				//this->removeChild(chess);
				board[px - i][py + i] = 0;
				chessing(turn, px - i, py + i);
				count = turn + 1;
			}
		}
		else if (//judge(turn, px, py) == 7 
		judge1[7] == 1
		&& board[px][py] == turn)//7为x+1,y-1
		{
			int search;
			for (search = 2; search <= 7 - px; search++)
			{
				if (board[px + search][py - search] == turn)
					break;
			}
			for (int i = search - 1; i >= 0; i--)
			{
				//board[px - search][py - search] = 0;
				//auto chess = (Sprite*)this->getChildByTag(100 * (px + i) + py-i);
				//this->removeChild(chess);
				board[px + i][py - i] = 0;
				chessing(turn, px + i, py - i);
				count = turn + 1;
			}
		}


		//判断胜负函数运行
	}
}