#include "game.h"

void game() //Ϊ�˷���������Ϸ������������һ��do whileѭ����
{
	int MINEFIELD[ROW][COL] = { 0 };
	char MINEFIELD_SHOW[ROW][COL] = { 0 };
	//PrintWelcome();//��ӡ��ӭ����

	do {
		system("cls");
		//PrintWelcome();//��ӡ��ӭ����
		InitMineField(MINEFIELD, ROW, COL);//��ʼ���洢����
		InitMineField_Show(MINEFIELD_SHOW, ROW, COL);//��ʼ��չʾ����		
		PrintMineField(MINEFIELD_SHOW, ROW, COL);

		while(ChangeMineField_Show(MINEFIELD, MINEFIELD_SHOW, ROW, COL))//�����û����룬�ı�չʾ����
		{
			PrintMineField(MINEFIELD_SHOW, ROW, COL);
		}

		PrintMineField(MINEFIELD_SHOW, ROW, COL);//��Ϸ����ʱ����ȫ������λ��
		printf("Press any key to restart;Enter '0' to exit.\n");
	} while (_getch() != 48);//48��0��ascii��ֵ
	//ѭ�����룬���������ظ�������Ϸ��������ÿ�ζ�Ҫ���´�
}


int main()
{
	game();
	return 0;
}
