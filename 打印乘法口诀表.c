#include <stdio.h>

void dycfkjb()//��ӡ �˷��ھ���

{
	for(int i = 0;i<=9;i++)
	{ 
		for (int j = 1; j <= i; j++)
			printf("%d*%d=%-2d ", j, i, i * j);
		printf("\n");
	}
}

//int main()
//{
//	dycfkjb();
//}