#include <stdio.h>

void dycfkjb()//´òÓ¡ ³Ë·¨¿Ú¾÷±í

{
	for(int i = 0;i<=9;i++)
	{ 
		for (int j = 1; j <= i; j++)
			printf("%d*%d=%-2d ", j, i, i * j);//%-2d的作用是对齐
		printf("\n");
	}
}

//int main()
//{
//	dycfkjb();
//}
