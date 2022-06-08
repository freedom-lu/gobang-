#pragma once
#include "game.h"
void initBoard(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			board[i][j] = ' ';             //����ʼ��ֵ,�ո�
		}
	}
}
void displayBoard(char board[ROW][COL], int row, int col) //��ӡ��   row ���У�col����
{
	for (int a = 0; a < col; a++)
	{
		for (int i = 0; i < row; i++)
		{
			printf(" %c ", board[a][i]);     // �ո����룬�ո�
			if (i != row - 1)          //���һ�β���Ҫ��ӡ|����Ϊ������
			{
				printf("|");
			}
		}
		printf("\n");
		if (a != col - 1)                    //���һ��Ҳ�ǲ���Ҫ��ӡ���
		{
			for (int i = 0; i < row; i++)     //�ָ���
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

	//�������
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int a, b;
	while (1)
	{
		printf("�����\n");
		printf("��������Ҫ�µ�λ��->");
		scanf("%d %d", &a, &b);

		//�ж��������ֺϷ���
		if ((a > 0 && a <= row) && (b > 0 && b <= col))
		{
			if (board[a - 1][b - 1] == ' ')    //�ж��û�����ĵط��Ƿ��Ѿ�������
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
			printf("�����������������\n");
		}
	}
}
//��������
void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("������->\n");
	while (1)
	{
		int x = rand() % row;   //�������������
		int y = rand() % col;
		if (board[x][y] == ' ')   //�ж�λ���Ƿ�ռ��
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
				return 0;		//û��
			}
		}
	}
	return 1;		//����
}
char IsWin(char board[ROW][COL], int row, int col)   //�ж���Ӯ
{
	for (int i = 0; i < row; i++)       //�ж���û���˺��ŵ�Ӯ��
	{
		int a = 0;
		for (int j = 1; j < col; j++)
		{
			if (board[i][0] == board[i][j] && board[i][0] != ' ' )   //�ж�������ǰ��һ���Ƿ������!= �ո�
			{	
				a += 1;       //�����ȣ�a++
				if (a == (col - 1))        //�����i��ȫ����Ԫ������Ҳ�Ϊ�ո�
					return board[i][1];
			}
			else
			{
				break;
			}
		}
	}
	for (int i = 0; i < row; i++)      //�ж����ŵ���û��Ӯ�� 
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
	for (int i = 1; i < row; i++)     //�ж�б�ŵ�1
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
	for (int i = 1; i < row; i++)      //�ж�б�ŵ�2
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
