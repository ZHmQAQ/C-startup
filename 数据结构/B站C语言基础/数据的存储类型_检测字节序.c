//�жϵ�ǰ�����ֽ���
//˼·���鿴һ���ض����� ����λ�����磬�������� 1
//����Ǵ�˴洢���Ǿ��� 00 00 00 01
//�����С�˴洢���Ǿ��� 01 00 00 00
//�� char ���͵�ָ��ѵ�һλ�ó�����
#include <stdio.h>
int check_sys()
{
	//�����ǰ�ڴ�洢ģʽ��С�ˣ����� 1�����򷵻� 0
	int a = 1;
	char* p = (char*)&a;
	return *p;
}
//int main()
//{
//	int a = 1;
//	char* p = (char*)&a;
//	//printf("%c", a);
//	if (*p == 1)
//		printf("С��");
//	else
//		printf("С��");
//	return 0;
//}

int main()
{
	//int a = 0b11111111111111111111111111111111;
	//char a = -1;
	//signed char b = -1;
	//unsigned char c = -1;
	//printf("%d\n%d\n%d\n", a,b,c);
	char a = -128;
	printf("%u\n", a);
}
