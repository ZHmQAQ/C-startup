//判断当前机器字节序
//思路：查看一个特定数字 的首位，例如，对于数字 1
//如果是大端存储，那就是 00 00 00 01
//如果是小端存储，那就是 01 00 00 00
//用 char 类型的指针把第一位拿出来。
#include <stdio.h>
int check_sys()
{
	//如果当前内存存储模式是小端，返回 1；否则返回 0
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
//		printf("小端");
//	else
//		printf("小端");
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
