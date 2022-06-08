#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 5             //���̴�С�޸�
#define COL 5            //���̴�С�޸�
//��ʼ��

void initBoard(char board[ROW][COL], int row, int col);

//��ӡ����

void displayBoard(char board[ROW][COL], int row, int col);

//������� (*)

void PlayerMove(char board[ROW][COL], int row, int col);

//�������� (#)

void ComputerMove(char board[ROW][COL], int row, int col);
/*
��û����Ӯ��
     *     ���Ӯ��
     #     ����Ӯ��
     e     ƽ��
     c     ��Ϸû����������
*/

char IsWin(char board[ROW][COL], int row, int col);

int IsFull(char board[ROW][COL], int row, int col);

