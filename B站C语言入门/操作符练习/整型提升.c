#include <stdio.h>

int main()
{
	char a = 3;
	char b = 127;//ע�⣬127 �պ��� 8 ������λ��1 ���ֽڣ����ܴ洢���������
	char c = a + b;
	printf("%d\n", c);//ע�⣬�����ӡ��ռλ���� %d ������ %c
	//��ӡ����� -126
	return 0;
}