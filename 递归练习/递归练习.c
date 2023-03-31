#include <stdio.h>

//##########打印每一位##########
void num_Print(unsigned int n)
{
	//思路：%10、/10,逆序输出
	if (n >= 10)
		num_Print(n / 10);
	printf("%d ", n%10);
}

//##########字符串长度##########
int get_str_Len(char* ch)
{
	//char* ch表示输入的字符串的指针，从头到尾扫一遍，如果出现\0就终止
	if (*ch == '\0')
		return 0;
	return 1 + get_str_Len(ch+1);//ch+1，即指针往后移动一格
	//对于指针，我还是不甚了解……
	//数组传参，传过去的不是整个数组，而是首元素的地址
}

//##########求n的阶乘##########
int factorial(int n)
{
	if (n == 0)
		return 1;
	return factorial(n - 1) * n;
}

//##########求斐波那契数列第n项##########
int fibonacci(int n)
{
	//斐波那契数列：1,1,2,3,5,8,13……
	//当n>=3，a(n) = a(n-1)+a(n-2)
	if (n == 1 || n == 2)
		return 1;
	return fibonacci(n - 1) + fibonacci(n - 2);
	//程序时间复杂度O(2^n)，效率非常低下
	//虽然代码精简逻辑简单，但是这种情况下还是不应该用递归
}

int fibonacchi_opt1(int n)
{
	//求斐波那契数优化版
	//opt的意思是optimized，优化版
	//因为递归是逆推，循环是正推，且可以储存数据，尝试使用循环的方法
	long n1 = 1;
	long n2 = 1;
	long n3 = 0;
	for (int i = 2; i < n; i++)
	{
		n3 = n2 + n1;
		n1 = n2;
		n2 = n3;
	}
	return n3;
}

//##########汉诺塔问题##########
int global_tot = 0;//计数变量
int Hanoi_Tower(int n,char X, char Z,char Y)
{
	//n是初始柱上的元素个数，X是初始柱，Z是目标柱，Y是辅助柱，
	//其实就是ABC柱子，但是为了防止混淆,所以切换了一个称谓
	if (n == 0)
		return 0;
	Hanoi_Tower(n - 1, X, Y, Z);
	global_tot++;
	printf("%6d %c -> %c\n",global_tot,X, Z);
	Hanoi_Tower(n - 1, Y, Z, X);
}

int main()
{
	////##########打印每一位##########
	//unsigned int n;
	//n = 1145141919;
	//num_Print(n);

	////##########字符串长度##########
	//char ch[20] = {1,2,4,5,5,0};
	//printf("%d\n", get_str_Len(ch));

	////##########求n的阶乘##########
	//printf("%d\n", factorial(3));

	////##########求斐波那契数列第n项##########
	////printf("%d\n", fibonacci(50));//非常缓慢，时间复杂度太高了。
	//printf("%d\n",fibonacchi_opt1(40));//很快嗷

	////##########汉诺塔问题##########
	//char A = 'A';
	//char B = 'B';
	//char C = 'C';
	//int n = 4;
	//Hanoi_Tower(n, A, C, B);

}