#include "game.h"

void deleteLine(int n)//n 是上一行的字符数
{
	COORD pos = { 0 }; // 光标位置
	DWORD dwWritten = 0; // 写入字符数
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE); // 控制台句柄
	FillConsoleOutputCharacter(hOut, ' ', n, pos, &dwWritten); // 清空输出行
	SetConsoleCursorPosition(hOut, pos); // 将光标移至行首
}