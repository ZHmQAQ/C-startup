#include <stdio.h>
#define NUMBER 20

//##########冒泡排序##########
int bubble_Sort(int arr[],int len)
{
	//冒泡排序
	//int arr_length = sizeof(arr) / sizeof(int);//试图计算数组元素个数。
	//注意，这个函数传参的时候，传的是数组第一个元素的地址，而不是整个数组，所以不能用这种方法。
	//在函数外面这样做是没有问题的，但是传参之后就不对了。
	// 所以应该直接把数组长度作为变量传进来。
	//int arr_length = 18;
	int i = 0;//控制循环趟数
	int j = 0;//控制每趟的检查次数
	int sign = 0;//检查这一趟是否进行过元素修改，如果没有进行过，跳出循环。
	for (i = 0; i < len - 1; i++)//扫描 n - 1 趟
	{
		sign = 0;//初始化sign
		for (j = 0; j < len - i - 1; j++)//检查 n - i 次
		{
			if (arr[j] > arr[j+1])
			{
				int temp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j]= temp;
				sign = 1;//发生了修改，那么sign = 1
			}

		}
		if (sign == 0)//上一趟没有发生过修改，那么说明已经排好了。
			break;
	}
	return arr;
}


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

	////##########二维数组##########
	//int arr[3][4] = {1,2,3,4,5}; //不完全初始化，等同于{{1,2,3,4},{5}}，一行一行地填写
	//1 2 3 4
	//5 0 0 0
	//0 0 0 0
	//int arr[3][4] = { {1,2,3},{4,5} }; //大括号可以插在里面
	//1 2 3 0
	//4 5 0 0
	//0 0 0 0 
	//int arr2[][] = {1,2,3,4,5}; //不能用这种方式初始化,列（后面那个）不可以省略
	//int arr2[][4] = { 1,2,3,4,5,6 }; //这种方式可以
	//二维数组在内存中的存放

	////##########数组排序##########
	//int arr[] = {1, 2, 9, 5, 4, 8, 6, 3, 7,123,654,123,645,3,654,6,45,6354};
	//int arr_length = sizeof(arr) / sizeof(int);
	//bubble_Sort(arr,arr_length);
	//for (int i = 0; i < arr_length; i++)
	//	printf("%d ", arr[i]);

	////##########数组指针##########
	//int arr[] = { 1,2,3,4,5,6 };
	//printf("%p\n", arr);//0000001EF072FBF8
	//printf("%p\n", arr[0]);//0000000000000001 没有用到解引用符号x
	//printf("%p\n", &arr[0]);//0000001EF072FBF8
	//printf("%d\n", *arr);// 1

	//printf("%p\n", arr);//首元素地址000000BFE88FF798
	//printf("%p\n", arr + 1);//000000BFE88FF79C

	//printf("%p\n", &arr);//数组的地址000000BFE88FF798
	//printf("%p\n", &arr + 1);//000000BFE88FF7B0

	
	
	return 0;
}