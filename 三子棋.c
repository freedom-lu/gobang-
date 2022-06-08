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
	initBoard(board, ROW, COL);   //����ʼ��ֵ
	displayBoard(board, ROW, COL);   //��ӡ����������
	char estimate;  //�ж���Ϸ�Ƿ����
	while (1)
	{
		//�������
		PlayerMove(board, ROW, COL);       
		displayBoard(board, ROW, COL);   //��ӡ����������
		estimate = IsWin(board, ROW, COL);  //�ж��Ƿ�Ӯ�� ���Ӯ����*������#��ƽ��e����û����c
		if (estimate != 'c')   //�������ֵ����c,������Ϸ������break����ѭ��
		{
			break;
		}
		//��������
		ComputerMove(board, ROW, COL);
		displayBoard(board, ROW, COL);   //��ӡ����������
		estimate = IsWin(board, ROW, COL);
		if (estimate != 'c')   
			break;
	}
	printf("%d\n", estimate);
	if (estimate == '*')
	{
		printf("���Ӯ��\n");
	}
	if (estimate == '#')
	{
		printf("����Ӯ��\n");
	}
	if (estimate == 'E')
	{
		printf("ƽ��\n");
	}
	displayBoard(board, ROW, COL);   //��ӡ����������

}
int main()
{
	int input;
	srand((unsigned int)time(NULL));   //�����������
	do
	{
		manu();
		printf("enter->");
		scanf("%d", &input);
		switch (input)  //�ж��û��벻������Ϸ
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