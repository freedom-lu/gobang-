#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 5             //棋盘大小修改
#define COL 5            //棋盘大小修改
//初始化

void initBoard(char board[ROW][COL], int row, int col);

//打印棋盘

void displayBoard(char board[ROW][COL], int row, int col);

//玩家下棋 (*)

void PlayerMove(char board[ROW][COL], int row, int col);

//电脑下棋 (#)

void ComputerMove(char board[ROW][COL], int row, int col);
/*
有没有人赢了
     *     玩家赢了
     #     电脑赢了
     e     平局
     c     游戏没结束，继续
*/

char IsWin(char board[ROW][COL], int row, int col);

//判断棋盘是否满了且没有人赢
int IsFull(char board[ROW][COL], int row, int col);

