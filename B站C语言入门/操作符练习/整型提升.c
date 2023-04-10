#include <stdio.h>

int main()
{
	char a = 3;
	char b = 127;//注意，127 刚好是 8 个比特位（1 个字节）所能存储的最大整数
	char c = a + b;
	printf("%d\n", c);//注意，这里打印的占位符是 %d 而不是 %c
	//打印结果是 -126
	return 0;
}