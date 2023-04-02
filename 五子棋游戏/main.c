#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include "game.h"
#include "main.h"

/*
井字棋游戏：两位玩家，执黑执白，轮流在3*3的棋盘上放棋子，
如果横向/竖向/斜向连成一线，则该颜色棋子获胜。

   |   | 
---|---|---
   |   | 
---|---|---
   |   | 
*/

void game()
{
	char board[ROW][COL] = {0};
	InitBoard(board, ROW, COL);
	DisplayBoard(board,ROW,COL);
	while(1)
	{
		PlayerMove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);
		if (WuziqiWin('*',board,ROW,COL))
			break;
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		if (WuziqiWin('#', board, ROW, COL))
			break;
	}
}


void menu()
{
	printf("**************井字棋**************\n");
	printf("*********1.play    0.exit*********\n");
	printf("**********************************\n");
}

void test() 
{
	int input = 0;
	do
	{
		menu();
		printf("choose:>");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			printf("游戏开始\n");
			game();
			break;
		case 0:
			printf("退出成功\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}
