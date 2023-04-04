#include "game.h"

void PrintWelcome()
{
	//��Ϸ����ʱ����˸Ч��
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
	int totalmine = (int)COL * ROW * DENSITY;//�����ܵĵ��׸���
	int mine = 0;//�Ѿ�����ĵ��׸���
	for (int i = 0; i < ROW; i++)
		for (int j = 0; j < COL; j++)
			minefield[i][j] = 0;
	while (1)
	{
		for (int i = 0; i < ROW; i++)
			for (int j = 0; j < COL; j++)
			{
				float p = (float)rand() / RAND_MAX;//����һ��0~1֮��������
				if (p >= DENSITY / 100 && minefield [i][j]!= -1)
					minefield[i][j] = 0;
				else
				{
					if (minefield[i][j] != -1)
						mine++;
					minefield[i][j] = -1;//��DENSIYTY/100�ĸ��ʲ������			
				}
				if (mine == totalmine)
					goto mine_set_finish;
			}
	}
mine_set_finish://���ײ�����ϣ���ǰ�е��׵�λ�ö���-1��û�е��׵�λ�ö���0
	//printf("���ײ�����ϣ�\n");
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
	//printf("��ʼ����ɣ�\n");
	//Sleep(500);
}

void PrintMineField(char minefield_show[ROW][COL], int row, int col)
{
	//���õġ������塱�ļ���Ĵ�ӡ���̵Ĵ���
	system("cls");
	printf("   ");
	for (int k = 0; k < COL; k++)
		printf("|%3d", k);//��ӡ�б�
	printf("|\n");
	for (int i = 0; i < ROW; i++)
	{
		printf("---");
		for (int k = 0; k < COL; k++)
			printf("|---");//��ӡ������ĺ�����
		printf("|\n");

		printf("%-3d", i);
		for (int j = 0; j < COL; j++)
			printf("| %c ", minefield_show[i][j]);//���д�ӡ������
		printf("|\n");
	}
	for (int k = 0; k < COL; k++)
		printf("---|");//��ӡ���һ�е������Ե
	printf("---|\n   ");
	for (int k = 0; k < COL; k++)
		printf("|%3d", k);//��ӡ�б�
	printf("|\n");
	printf(" ");
	printf("\n����������%d\n", (int)(COL * ROW * DENSITY));
}

int IndexNotOut(int x, int y)//��������±��Ƿ�Խ��
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
	printf("�����������ִ���������꣬һ����ĸ�������,�ÿո���߻س�������\nx��Ǵ˴����ף�zΪ̽���˿顣\n");
	scanf("%d %d %c", &y,&x,&op);
	if (x ==-1||y== -1) //��������Ƿ��ǺϷ�
	{
		printf("���벻�Ϸ�������������\n");
		goto re_enter;
	}
	if (x < 0 || x >= ROW || y < 0 || y >= COL)//��������Ƿ�Խ��
	{
		printf("���벻�Ϸ�������������\n");
		goto re_enter;
	}
	if ( op == 'x')//�����
	{
		if (minefield_show[x][y] == 'x')
		{
			printf("�����Ѿ���ǹ���\n");
			goto re_enter;
		}

		else if (isdigit(minefield_show[x][y]))
		{
			printf("�����Ѿ�������\n");
			goto re_enter;
		}
		else
		{
			printf("��ǳɹ�\n");
			minefield_show[x][y] = 'x';
			if (JudgeWin(minefield, minefield_show, ROW, COL))
			{
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n#*#*#*#*#*��Ӯ�ˣ����*#*#*#*#*#\n");
				Sleep(1500);
				return 0;
			}
			else
				return 1;
		}
	}
	else if (isdigit(minefield_show[x][y]))//��������λ���Ƿ��Ѿ���̽���
	{
		printf("�����Ѿ�������\n");
			goto re_enter;
	}
	else if (minefield[x][y] == 0)//����Ƿ���0���ӣ�����ǵĻ����Զ��ҿ���Χ8��
	{
		AutoShow(minefield, minefield_show, x, y);
	}
	else if (minefield[x][y] == -1 )//����Ƿ����
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n#*#*#*#*#*��ը�ˣ����*#*#*#*#*#\n");
		Sleep(1500);
		RevealMineField_Show(minefield, minefield_show, x, y);//��Ϸ����ʱ����ȫ������λ��
		return 0;
	}
	else
		minefield_show[x][y] = '0' + minefield[x][y];//�������Ϸ�������û��ը������û�б��ף���ʾ�ÿ������
	return 1;
}

void RevealMineField_Show(int minefield[ROW][COL], char minefield_show[ROW][COL], int x, int y)
{
	for (int i = 0; i < ROW; i++)
		for (int j = 0; j < COL; j++)
		{
			if (minefield[i][j] == -1 && minefield_show[i][j] == 'x')
				minefield_show[i][j] = 'v';//����˵�λ��
			if (minefield[i][j] == -1 && minefield_show[i][j] == ' ')
				minefield_show[i][j] = '*';//��û�굽��λ��
		}
	minefield_show[x][y] = 'X';//�´�֮�����˵�λ��
}

void AutoShow(int minefield[ROW][COL], char minefield_show[ROW][COL], int x, int y)
{
	if (minefield[x][y] == 0)
	{
		minefield_show[x][y] = '0';
		minefield[x][y] = -2;//��ʶ������ֹ��ͷɨ��
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
