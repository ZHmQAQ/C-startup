#include <stdio.h>
#define NUMBER 20

int main()
{
	////##########数组的声明##########
	//int arr1[20]; //要先声明数据类型，int,char,float啥的都行。其他数据结构可以吗？
	//char arr2[NUMBER]; //没有问题
	////int m = 20;
	////char arr3[m]; //报错
	////const int n = 20;
	////char arr3[n]; //报错

	////##########数组的初始化##########
	//int arr1[10] = { 1, 2, 3 }; //不完全初始化，剩下的元素默认初始化为0
	//char arr2[10] = { 'a', 'b', 98 }; //对于字符来说，元素需要加单引号，也可以用不加单引号的int类型，会自动转译为ascii码对应的字符
	//char arr3[10] = "abc"; //字符数组（字符串）也可以用双引号初始化
	//char arr4[] = "abcde"; //如果不先填入数组长度，则会自动初始化为arr[6]，这里是6是因为最后加入了一个“\0”作为字符串结束符号（int类型的数组是没有的）

	////##########数组的访问##########
	//char arr6[] = "abcde";
	//int i = 0;
	//for (i = 0; i < 6; i++) //6是数组长度
	//	printf("%c ", arr6[i]); //arr[i] 这个变量里的[]代表了下标访问符

	////##########数组地址##########
	//int arr5[] = { 1,2,3,4,5 };
	//int sz = sizeof(arr5) / sizeof(int);
	//for (int i = 0;i<=sz;i++)
	//	printf("%d %p\n",i,&arr5[i]);

	//##########二维数组##########
	int arr[3][4] = {1,2,3,4,5}; //不完全初始化，等同于{{1,2,3,4},{5}}，一行一行地填写
	//1 2 3 4
	//5 0 0 0
	//0 0 0 0
	int arr[3][4] = { {1,2,3},{4,5} }; //大括号可以插在里面
	//1 2 3 0
	//4 5 0 0
	//0 0 0 0 
	//int arr2[][] = {1,2,3,4,5}; //不能用这种方式初始化,列（后面那个）不可以省略
	int arr2[][4] = { 1,2,3,4,5,6 }; //这种方式可以
	//二维数组在内存中的存放
	return 0;
}