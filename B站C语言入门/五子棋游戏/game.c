#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
#define MAX_BUFFER_SIZE 1024


void InitBoard(char board[ROW][COL], int row, int col)
{
	//初始化棋盘
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void DisplayBoard(char board[ROW][COL], int row, int col)
{
	//显示棋盘
	printf("   ");
	for (int k = 0; k < col; k++)
		printf("|%3d",k);//打印行标
	printf("|\n");
	for (int i = 0; i < row; i++)
	{
		printf("---");
		for (int k = 0; k < col; k++)
			printf("|---");//打印棋盘的行
		printf("|\n");

		printf("%-3d", i);
		for (int j = 0;j<col;j++)
			printf("| %c ",board[i][j]);//按行打印棋盘元素
		printf("|\n");
	}
	for (int k = 0; k < col; k++)
		printf("---|");//打印最后一行棋盘边缘
	printf("---|\n   ");
	for (int k = 0; k < col; k++)
		printf("|%3d", k);//打印行标
	printf("|\n");
	printf(" ");
}

void PlayerMove(char board[ROW][COL], int raw, int col)
{
	while (1)
	{
	int x = 0;
	int y = 0;
	printf("*玩家行动*\n输入横 纵，以空格隔开\n请输入坐标-> ");
	scanf_s("%d %d", &y, &x);

		if (x >= 0 && x < raw && y >= 0 && y < col)
		{
			if (board[x][y] == ' ')
			{
			board[x][y] = '*';
			break;
			}
			else
				printf("不能下在这里。\n");
		}
		else
		{
			printf("坐标非法，请重新输入！0~%d 0~%d\n",raw,col);
		}
	}
	system("cls");
}

void ComputerMove(char board[ROW][COL], int raw, int col)
{
	int x = 0;
	int y = 0;
	printf("*电脑行动*\n");
	//SendBoardData(board,ROW,COL);//把现在的棋盘数据发送到Ai
	while (1)
	{
		int x = 0;
		int y = 0;
		scanf_s("%d %d", &y, &x);
		if (x >= 0 && x < raw && y >= 0 && y < col)
		{
			if (board[x][y] == ' ')
			{
				board[x][y] = '#';
				break;
			}
			else
				printf("不能下在这里。\n");
		}
		else
		{
			printf("坐标非法，请重新输入！0~%d 0~%d\n", raw, col);
		}
	}
	system("cls");
}

int WuziqiWin(char ch, char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for(i = 0;i<row;i++)
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ch)
			{
				if ((board[i][j] == board[i][j + 5] && board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2] && board[i][j] == board[i][j + 3] && board[i][j] == board[i][j + 4]) ||  //横向相等
					(board[i][j] == board[i + 5][j + 5] && board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 2][j + 2] && board[i][j] == board[i + 3][j + 3] && board[i][j] == board[i + 4][j + 4]) || //斜向右下相等
					(board[i][j] == board[i + 5][j] && board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j] && board[i][j] == board[i + 3][j] && board[i][j] == board[i + 4][j]) ||//纵向相等
					(board[i][j] == board[i + 5][j - 5] && board[i][j] == board[i + 1][j - 1] && board[i][j] == board[i + 2][j - 2] && board[i][j] == board[i + 3][j - 3] && board[i][j] == board[i + 4][j - 4]))//斜向左下相等
				{
					printf("游戏结束\n");
					if (ch == '*')
						printf("玩家获胜！！！");
					if (ch == '#')
						printf("电脑获胜！！！");
					return 1;
				}
			}
		}
	return 0;
}
//void SendBoardData(char board[ROW][COL],int row,int col)
//{
//	char buffer[MAX_BUFFER_SIZE];
//	int sz = row * col;
//	for(int i =0;i<row;i++)
//		sprintf(buffer, "%s\n", board[i]);
//	buffer[sz + 1] = '\0';
//	SetClipboard(board);
//}
//void SetClipboard(char* buffer) 
//{
//	HGLOBAL hGlobal;
//	LPSTR   lpstr;
//
//	OpenClipboard(NULL);
//	EmptyClipboard();
//
//	hGlobal = GlobalAlloc(GMEM_ZEROINIT, strlen(buffer) + 1);
//	lpstr = (LPSTR)GlobalLock(hGlobal);
//	strcpy(lpstr, buffer);
//	GlobalUnlock(hGlobal);
//
//	SetClipboardData(CF_TEXT, hGlobal);
//	CloseClipboard();
//}
