#include "game.h"

void PrintWelcome()
{
	//游戏加载时的闪烁效果
	for(int i =0;i<3;i++)
	{
		printf("**********WELCOME TO MINE SWEEPING**********\n");
		Sleep(500);
		deleteLine(strlen("**********WELCOME TO MINE SWEEPING**********\n"));
		Sleep(500);
	}
	printf("**********WELCOME TO MINE SWEEPING**********\n");
}

void InitMineField(int minefield[ROW][COL], int row, int col)
{
	srand(time(NULL));
mine_set_start:	
	;
	int totalmine = (int)COL * ROW * DENSITY;//计算总的地雷个数
	int mine = 0;//已经布设的地雷个数
	for (int i = 0; i < ROW; i++)
		for (int j = 0; j < COL; j++)
			minefield[i][j] = 0;
	while (1)
	{
		for (int i = 0; i < ROW; i++)
			for (int j = 0; j < COL; j++)
			{
				float p = (float)rand() / RAND_MAX;//生成一个0~1之间的随机数
				if (p >= DENSITY / 100 && minefield [i][j]!= -1)
					minefield[i][j] = 0;
				else
				{
					if (minefield[i][j] != -1)
						mine++;
					minefield[i][j] = -1;//以DENSIYTY/100的概率布设地雷			
				}
				if (mine == totalmine)
					goto mine_set_finish;
			}
	}
mine_set_finish://地雷布设完毕，当前有地雷的位置都是-1，没有地雷的位置都是0
	//printf("地雷布设完毕！\n");
	//Sleep(500);
	for (int i = 0; i < ROW; i++)
		for (int j = 0; j < COL; j++)
		{
			int count = 0;
			if (minefield[i][j] == -1)
				continue;
			else
			{
				if (IndexNotOut(i-1, j -1))
					if (minefield[i-1][j - 1] == -1)
						count++;
				if (IndexNotOut(i-1, j ))
					if (minefield[i - 1][j ] == -1)
						count++;
				if (IndexNotOut(i-1, j + 1))
					if (minefield[i-1][j + 1] == -1)
						count++;
				if (IndexNotOut(i+1, j ))
					if (minefield[i+1][j ] == -1)
						count++;
				if (IndexNotOut(i+1, j - 1))
					if (minefield[i+1][j - 1] == -1)
						count++;
				if (IndexNotOut(i+1, j - 1))
					if (minefield[i+1][j + 1] == -1)
						count++;
				if (IndexNotOut(i, j + 1))
					if (minefield[i][j + 1] == -1)
						count++;
				if (IndexNotOut(i , j - 1))
					if(minefield[i ][j-1] == -1 )
						count++;
			}
			minefield[i][j] = count;
		}
	//printf("初始化完成！\n");
	//Sleep(500);
}

void PrintMineField(char minefield_show[ROW][COL], int row, int col)
{
	//借用的“五子棋”文件里的打印棋盘的代码
	system("cls");
	printf("   ");
	for (int k = 0; k < COL; k++)
		printf("|%3d", k);//打印行标
	printf("|\n");
	for (int i = 0; i < ROW; i++)
	{
		printf("---");
		for (int k = 0; k < COL; k++)
			printf("|---");//打印地雷阵的横向间隔
		printf("|\n");

		printf("%-3d", i);
		for (int j = 0; j < COL; j++)
			printf("| %c ", minefield_show[i][j]);//按行打印地雷阵
		printf("|\n");
	}
	for (int k = 0; k < COL; k++)
		printf("---|");//打印最后一行地雷阵边缘
	printf("---|\n   ");
	for (int k = 0; k < COL; k++)
		printf("|%3d", k);//打印行标
	printf("|\n");
	printf(" ");
	printf("\n地雷总数：%d\n", (int)(COL * ROW * DENSITY));
}

int IndexNotOut(int x, int y)//检查数组下标是否越界
{
	if (x >= 0 && x < ROW && y >= 0 && y < COL)
		return 1;
	return 0;
}

void InitMineField_Show( char minefield_show[ROW][COL], int row, int col)
{
	for (int i = 0; i < ROW; i++)
		for (int j = 0; j < COL; j++)
			minefield_show[i][j] = ' ';
}

int ChangeMineField_Show(int minefield[ROW][COL], char minefield_show[ROW][COL], int row, int col)
{
	int x = -1;
	int y = -1;
	char op = ' ';
	//char input[20] = { 0 };
re_enter:
	printf("输入两个数字代表横纵坐标，一个字母代表操作,用空格或者回车隔开。\nx标记此处是雷，z为探索此块。\n");
	scanf("%d %d %c", &y,&x,&op);
	if (x ==-1||y== -1) //检查输入是否是合法
	{
		printf("输入不合法，请重新输入\n");
		goto re_enter;
	}
	if (x < 0 || x >= ROW || y < 0 || y >= COL)//检查输入是否越界
	{
		printf("输入不合法，请重新输入\n");
		goto re_enter;
	}
	if ( op == 'x')//检查标记
	{
		if (minefield_show[x][y] == 'x')
		{
			printf("这里已经标记过了\n");
			goto re_enter;
		}

		else if (isdigit(minefield_show[x][y]))
		{
			printf("这里已经来过了\n");
			goto re_enter;
		}
		else
		{
			printf("标记成功\n");
			minefield_show[x][y] = 'x';
			if (JudgeWin(minefield, minefield_show, ROW, COL))
			{
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n#*#*#*#*#*你赢了，伙计*#*#*#*#*#\n");
				Sleep(1500);
				return 0;
			}
			else
				return 1;
		}
	}
	else if (isdigit(minefield_show[x][y]))//检查输入的位置是否已经被探查过
	{
		printf("这里已经来过了\n");
			goto re_enter;
	}
	else if (minefield[x][y] == 0)//检查是否是0格子，如果是的话，自动揭开周围8格
	{
		AutoShow(minefield, minefield_show, x, y);
	}
	else if (minefield[x][y] == -1 )//检查是否踩雷
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n#*#*#*#*#*你炸了，伙计*#*#*#*#*#\n");
		Sleep(1500);
		RevealMineField_Show(minefield, minefield_show, x, y);//游戏结束时揭晓全部地雷位置
		return 0;
	}
	else
		minefield_show[x][y] = '0' + minefield[x][y];//如果输入合法，而且没有炸，而且没有标雷，显示该块的数字
	return 1;
}

void RevealMineField_Show(int minefield[ROW][COL], char minefield_show[ROW][COL], int x, int y)
{
	for (int i = 0; i < ROW; i++)
		for (int j = 0; j < COL; j++)
		{
			if (minefield[i][j] == -1 && minefield_show[i][j] == 'x')
				minefield_show[i][j] = 'v';//标对了的位置
			if (minefield[i][j] == -1 && minefield_show[i][j] == ' ')
				minefield_show[i][j] = '*';//还没标到的位置
		}
	minefield_show[x][y] = 'X';//猜错之后死了的位置
}

void AutoShow(int minefield[ROW][COL], char minefield_show[ROW][COL], int x, int y)
{
	if (minefield[x][y] == 0)
	{
		minefield_show[x][y] = '0';
		minefield[x][y] = -2;//标识符，防止回头扫描
		if (IndexNotOut(x - 1, y - 1))
			if (minefield[x-1][y-1] >= 0)
				AutoShow(minefield, minefield_show, x - 1, y - 1);
		if (IndexNotOut(x - 1, y + 1))
			if (minefield[x-1][y+1] >= 0)
				AutoShow(minefield, minefield_show, x - 1, y + 1);
		if (IndexNotOut(x + 1, y - 1))
			if (minefield[x+1][y-1] >= 0)
				AutoShow(minefield, minefield_show, x + 1, y - 1);
		if (IndexNotOut(x + 1, y + 1))
			if (minefield[x + 1][y + 1] >= 0)
				AutoShow(minefield, minefield_show, x + 1, y + 1);
		if (IndexNotOut(x + 1, y))
			if (minefield[x+1][y] >= 0)
				AutoShow(minefield, minefield_show, x + 1, y);
		if (IndexNotOut(x - 1, y))
			if (minefield[x - 1][y] >= 0)
				AutoShow(minefield, minefield_show, x - 1, y);
		if (IndexNotOut(x, y - 1))
			if (minefield[x][y-1] >= 0)
				AutoShow(minefield, minefield_show, x, y - 1);
		if (IndexNotOut(x, y + 1))
			if (minefield[x][y+1] >= 0)
				AutoShow(minefield, minefield_show, x, y + 1);
	}
	if (minefield[x][y] > 0)
	{
		minefield_show[x][y] = '0' + minefield[x][y];
		minefield[x][y] = -2;
	}

}

int JudgeWin(int minefield[ROW][COL], char minefield_show[ROW][COL], int row, int col)
{
	int count = 0;
	int totalmine = (int)COL * ROW * DENSITY;
	for (int i = 0; i < ROW; i++)
		for (int j = 0; j < COL; j++)
			if (minefield[i][j] == -1 && minefield_show[i][j] == 'x')
				count++;
	//printf(" %d\n%d\n", count,totalmine);
	//Sleep(10000);
	if (count == totalmine)
		return 1;
	return 0;
}
