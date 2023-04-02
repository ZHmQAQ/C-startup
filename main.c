#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include "game.h"
#include "main.h"

/*
��������Ϸ����λ��ң�ִ��ִ�ף�������3*3�������Ϸ����ӣ�
�������/����/б������һ�ߣ������ɫ���ӻ�ʤ��

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
	printf("**************������**************\n");
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
			printf("��Ϸ��ʼ\n");
			game();
			break;
		case 0:
			printf("�˳��ɹ�\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}