#include "game.h"

void game() //为了方便重新游戏，主函数中是一个do while循环。
{
	int MINEFIELD[ROW][COL] = { 0 };
	char MINEFIELD_SHOW[ROW][COL] = { 0 };
	//PrintWelcome();//打印欢迎界面

	do {
		system("cls");
		//PrintWelcome();//打印欢迎界面
		InitMineField(MINEFIELD, ROW, COL);//初始化存储矩阵
		InitMineField_Show(MINEFIELD_SHOW, ROW, COL);//初始化展示矩阵		
		PrintMineField(MINEFIELD_SHOW, ROW, COL);

		while(ChangeMineField_Show(MINEFIELD, MINEFIELD_SHOW, ROW, COL))//接收用户输入，改变展示矩阵
		{
			PrintMineField(MINEFIELD_SHOW, ROW, COL);
		}

		PrintMineField(MINEFIELD_SHOW, ROW, COL);//游戏结束时揭晓全部地雷位置
		printf("Press any key to restart;Enter '0' to exit.\n");
	} while (_getch() != 48);//48是0的ascii码值
	//循环输入，这样可以重复进行游戏，而不是每次都要重新打开
}


int main()
{
	game();
	return 0;
}
