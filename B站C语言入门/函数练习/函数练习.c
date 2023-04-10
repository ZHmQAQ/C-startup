#include <stdio.h>
#include <string.h>

//##########元素交换##########
void Swap(int* pa, int* pb) 
{
	//使用指针传参,完成交换（传址调用）（需要改变a和b的时候，就使用传址调用）
	int tmp = 0;
	tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

//##########素数判断##########
int is_Prime(int a)
{
	//用a除以每个比它小的数字，如果发现能除尽，就不是素数，返回0
	for (int i = 2; i < a; i++)//在除的时候省略1和a本身，因此注意边界条件。
	{
		if (0 == a % i)
			return 0;		
	}
	return 1;//没有找到任何因数，返回1
}

//##########闰年判断##########
int is_Runnian(int a)
{
	//如果是闰年，那就返回1，如果不是，那就返回0
	//闰年判定条件：每四年一次，每个百年少一次，每四百年多一次
	//例如，1900年不是闰年，但2000年，2004年都是闰年
	//被四整除且不能被100整除；能被400整除
	if ((a % 4 == 0 && a % 100 != 0) || a % 400 == 0)
		return 1;
	return 0;
}

//##########二分查找##########
int binsearch(char ch[], int x)
{
	//数组ch[]必须是升序的，例如{1,2,4,5,15,23,55,78}
	//x是要查找的元素，如果找到，则返回x下标，未找到则返回-1
	int top = strlen(ch)-1;//上标
	int bot = 0;//下标
	return binsearch_1(ch, x, bot, top);	
}

int binsearch_1(char ch[], int x, int bot, int top)
{
	//辅助函数，为了实现二分查找，需要一个含有四个参数的函数来实现递归调用
	//应该会有更好的方法，暂时还没有想到
	int mid = (top + bot) / 2;
	if (x == ch[mid])
		return mid;
	if (top <= bot)//没有找到
		return -1;
	if (x > ch[mid])
		return binsearch_1(ch, x, mid + 1, top);
	if (x < ch[mid])
		return binsearch_1(ch, x, bot, mid - 1);
}

//##########调用这个函数，会使得num值加1##########
void num_Plus(int* num)
{
	//要修改参数的值，就需要传递地址（传址调用）
	(*num)++;//要注意操作符的顺序，如果不加括号，就会先++再访问地址，听离谱的
}


//int main()
//{
//	//##########元素交换##########
//	//int a = 10;
//	//int b = 20;
//	//printf("before:\na = %d, b = %d\n\n", a, b);
//	//Swap(&a, &b);//由于函数需要传入的参数是int* 地址，因此在这里要用&传入地址
//	//printf("after:\na = %d, b = %d\n\n", a, b);
//
//	//##########素数判断(输出5000000以内的素数)##########
//	//for (int i = 0; i <= 5000000; i++)
//	//	if (is_Prime(i))
//	//		printf("%d\n", i);
//
//	//##########闰年判断##########
//	//输出1000年到2025年的所有闰年
//	//for (int i = 1000; i <= 2025; i++)
//	//{
//	//	if (is_Runnian(i))
//	//		printf("%d 是闰年\n", i);
//	//}
//
//	//##########二分查找##########
//	/*char ch[20] = { 1,2,3,5,7,14,33,56,59,80,101 };
//	int a1 = binsearch(ch, 1);
//	int a2 = binsearch(ch, 2);
//	int a56 = binsearch(ch, 56);
//	int a78 = binsearch(ch, 78);
//	printf("%d\n%d\n%d\n%d\n", a1, a2, a56, a78);*/
//
//	//##########调用这个函数，会使得num值加1##########
//	//int num = 0;
//	//for (int i = 0; i <= 10; i++)
//	//{
//	//	printf("%d\n", num);
//	//	num_Plus(&num);
//	//}
//		
//}
