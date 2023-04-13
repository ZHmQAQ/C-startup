#include <stdio.h>

int main()
{
    // //##########字符指针##########
    // //练习 1
    // char arr1[] = "abcdef";
    // char arr2[] = "abcdef";
    // char* p1 = "abcdef";
    // char *p2 = "abcdef";
    // if (arr1 == arr2)
    // //if (p1 == p2)
    // {
    //     printf("equal\n");
    // }
    // else
    //     printf("unequal\n");

    //##########指针数组##########
    //使用指针数组打印三个数组
    int arr1[] = {1,2,3,4,5};
    int arr2[] = {2,3,4,5,6};
    int arr3[] = {3,4,5,6,7};
    int* parr[] = {arr1, arr2, arr3};//二维数组！
    for(int i = 0; i< 3;i++)
        {
            for(int j = 0;j<5;j++)
            {
                printf("%d ",*parr[i]+j);
            }
        }





}