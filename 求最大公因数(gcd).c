#include <stdio.h>

int gcd(int a, int b)//շת��������������
{
	int c = a % b;
	if (c == 0)
		return b;
	else
		return gcd(b, c);
}
//����
//int main()
//{
//	printf("%d\n", gcd(20, 12));
//	printf("%d\n", gcd(12, 20));
//	printf("%d\n", gcd(11451419, 19810));
//}