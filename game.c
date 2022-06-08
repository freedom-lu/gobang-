#pragma once
#include "game.h"
void initBoard(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			board[i][j] = ' ';             //赋初始化值,空格
		}
	}
}
void displayBoard(char board[ROW][COL], int row, int col) //打印表   row 是行，col是列
{
	for (int a = 0; a < col; a++)
	{
		for (int i = 0; i < row; i++)
		{
			printf(" %c ", board[a][i]);     // 空格，输入，空格
			if (i != row - 1)          //最后一次不需要打印|，因为到底了
			{
				printf("|");
			}
		}
		printf("\n");
		if (a != col - 1)                    //最后一行也是不需要打印这个
		{
			for (int i = 0; i < row; i++)     //分割行
			{
				printf("---");
				if (i != row - 1)
				{
					printf("|");
				}
			}
		}
		printf("\n");
	}
}

	//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int a, b;
	while (1)
	{
		printf("玩家下\n");
		printf("请输入你要下的位置->");
		scanf("%d %d", &a, &b);

		//判断输入数字合法性
		if ((a > 0 && a <= row) && (b > 0 && b <= col))
		{
			if (board[a - 1][b - 1] == ' ')    //判断用户输入的地方是否已经有数字
			{
				board[a - 1][b - 1] = '*';
				break;
			}
			else
			{
				printf("error, enter another words again!\n");
			}

		}
		else
		{
			printf("输入错误，请重新输入\n");
		}
	}
}
//电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("电脑下->\n");
	while (1)
	{
		int x = rand() % row;   //生成两个随机数
		int y = rand() % col;
		if (board[x][y] == ' ')   //判断位置是否被占用
		{
			board[x][y] = '#';
			break;
		}
	}
}
int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;		//没满
			}
		}
	}
	return 1;		//满了
}
char IsWin(char board[ROW][COL], int row, int col)   //判断输赢
{
	for (int i = 0; i < row; i++)       //判断有没有人横着的赢了
	{
		int a = 0;
		for (int j = 1; j < col; j++)
		{
			if (board[i][0] == board[i][j] && board[i][0] != ' ' )   //判断它和它前面一个是否相等且!= 空格
			{	
				a += 1;       //如果相等，a++
				if (a == (col - 1))        //代表第i行全部的元素相等且不为空格
					return board[i][1];
			}
			else
			{
				break;
			}
		}
	}
	for (int i = 0; i < row; i++)      //判断竖着的有没有赢了 
	{
		int a = 0;
		for (int j = 1; j < col; j++)
		{
			if (board[0][i] == board[j][i] && board[0][i] != ' ' )
			{
				a += 1;
				if (a == col -1)
					return board[1][i];
			}
			else
			{
				break;
			}
		}
	}
	int ad = 0;
	for (int i = 1; i < row; i++)     //判断斜着的1
	{
		
		if ((board[i - 1][i - 1] == board[i][i]) && (board[i][i] != ' ') )
		{
			ad++;
			if (ad == row - 1)
			{
				return board[i-1][i-1];
			}
		}
	}
	int as = 0;
	for (int i = 1; i < row; i++)      //判断斜着的2
	{
		if ( (board[i-1][row-i] == board[i][row-i-1]) && (board[i][row - i - 1] != ' ') )
		{
			as++;
			if (as == row - 1)
			{
				return board[i][row - i - 1];
			}
		}
	}
	if (IsFull(board, row, col) == 1)
	{
		return 'E';
	}
	if (IsFull(board, row, col) == 0)
	{ 
		return 'c';
	}
}
