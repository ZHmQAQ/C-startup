## 归并排序
用到递归的方法。核心函数：
```c
void merge_sort(int* arr, int length);
void split(int* arr, int* arrTemp, int left, int right);
void merge(int* arr, int* arrTemp, int left, int mid, int right);
```
代码：
```c
#include <stdio.h>
#include <stdlib.h>

void split(int* arr, int* arrTemp, int left, int right)
{
    int mid = (left + right) / 2;
    if (left < right)
    {
        split(arr, arrTemp, left, mid);
        split(arr, arrTemp, mid + 1, right);
        merge(arr, arrTemp, left, mid, right);
    }
}
void merge_sort(int* arr, int length)
{
    int* arrTemp = (int*)malloc(length * sizeof(int));
    split(arr, arrTemp, 0, length - 1);
    free(arrTemp);
}
void merge(int* arr, int* arrTemp, int left, int mid, int right)
{
    int l_pos = left;
    int r_pos = mid+1;
    int pos = left;
    while (l_pos <= mid && r_pos <= right)
    {
        if (arr[l_pos] < arr[r_pos])
        {
            arrTemp[pos] = arr[l_pos];
            pos++;
            l_pos++;
        }
        else
        {
            arrTemp[pos] = arr[r_pos];
            pos++;
            r_pos++;
        }
    }
    while (l_pos <= mid)
    {
        arrTemp[pos] = arr[l_pos];
        pos++;
        l_pos++;
    }
    while (r_pos <= right)
    {
        arrTemp[pos] = arr[r_pos];
        pos++;
        r_pos++;
    }
 	while (left <= right)
	{ 
	arr[left] = arrTemp[left];
	left++;
	}
}
void arrprint(int* arr, int length)
{
    for (int i = 0; i < length; i++)
        printf("%d ", arr[i]);
}
//##################################//
void test()
{
    int arr[14] = { 10,9,8,7,6,5,4,3,2,1,818181,4394949,727272,5757 };
    int length = 14;
    merge_sort(arr, length);
    arrprint(arr, length);
}
int main()
{
    test();
}
```
## 快速排序












## 堆排序










