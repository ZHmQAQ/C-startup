//###########找数##########
//有一串数列，其中有一个数字只出现了一次，其他数字均出现了两次。
//用尽量少的时间和空间，完成查找任务。

//我的解决方案
//？？这不就是括号匹配么
#include <stdio.h>
#define MAXSZ 4096
int findNum(int arr[], int n)
{
	//先尝试暴力法吧
	for (int i = 0; i < n; i++)
	{
		int flag = 1;
		for (int j = i + 1; j < n; j++)
			if (arr[i] == arr[j])
			{
				flag = 0;
			}
		if (flag == 1)
			return i;
	}			
}

int main()
{
	int arr[11] = { 0,0,5,5,1,4,6,7,7,6,4 };
	printf("%d\n", findNum(arr, 11));
	return 0;
}
