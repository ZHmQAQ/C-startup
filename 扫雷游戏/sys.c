#include "game.h"

void deleteLine(int n)//n ����һ�е��ַ���
{
	COORD pos = { 0 }; // ���λ��
	DWORD dwWritten = 0; // д���ַ���
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE); // ����̨���
	FillConsoleOutputCharacter(hOut, ' ', n, pos, &dwWritten); // ��������
	SetConsoleCursorPosition(hOut, pos); // �������������
}