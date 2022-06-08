#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "game.h"
void manu()
{
	printf("***************************************\n");
	printf("***************************************\n");
	printf("*******                           *****\n");
	printf("*******    Input 1:start game     *****\n");
	printf("*******      Input 0 : exit       *****\n");
	printf("*******                           *****\n");
	printf("***************************************\n");
	printf("***************************************\n");
}
void game()
{
	char board[ROW][COL];
	initBoard(board, ROW, COL);   //赋初始化值
	displayBoard(board, ROW, COL);   //打印三子棋棋盘
	char estimate;  //判断游戏是否结束
	while (1)
	{
		//玩家下棋
		PlayerMove(board, ROW, COL);       
		displayBoard(board, ROW, COL);   //打印三子棋棋盘
		estimate = IsWin(board, ROW, COL);  //判断是否赢了 玩家赢返回*，电脑#，平局e，还没结束c
		if (estimate != 'c')   //如果返回值不是c,代表游戏结束，break跳出循环
		{
			break;
		}
		//电脑下棋
		ComputerMove(board, ROW, COL);
		displayBoard(board, ROW, COL);   //打印三子棋棋盘
		estimate = IsWin(board, ROW, COL);
		if (estimate != 'c')   
			break;
	}
	if (estimate == '*')
	{
		printf("玩家赢了\n");
	}
	if (estimate == '#')
	{
		printf("电脑赢了\n");
	}
	if (estimate == 'E')
	{
		printf("平局\n");
	}
	displayBoard(board, ROW, COL);   //打印三子棋棋盘

}
int main()
{
	int input;
	srand((unsigned int)time(NULL));   //随机数生成器
	do
	{
		manu();
		printf("enter->");
		scanf("%d", &input);
		switch (input)  //判断用户想不想玩游戏
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("error,please enter again!\n");
			break;
		}
	} while (input);
	return 0;
}
