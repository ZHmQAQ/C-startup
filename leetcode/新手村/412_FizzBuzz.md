> Problem: [412. Fizz Buzz](https://leetcode.cn/problems/fizz-buzz/description/)

[TOC]

# 思路
其实就是给一个n，生成一个n项的数组，其中的每个元素都是字符串。

# 解题方法
核心部位用四个`if`判断语句：
```c
//伪代码
if(i%3==0 && i%5==0){/*"FizzBuzz"*/}
if(i%3!=0 && i%5==0){/*"Buzz"*/}
if(i%3==0 && i%5!=0){/*"Fizz"*/}
if(i%3!=0 && i%5!=0){/*"i"*/}
```
对于前三个`if`之后的代码块的实现：使用`sprintf()`语句
```c
sprintf(buffer[x],"%s","Fizz");
```
注意`buffer`的缓冲区要先用`malloc`分配，分配的大小 x 是 要输入的字符串长度 +1，因为需要在末尾缀上`'\n'`
对于最后一个代码块，需要把整数变成字符，塞入字符数组。为了分配内存，需要先知道整数的位数，因此写一个函数实现这个功能。然后，逆序输出到字符串。最后在末尾加上`\0``
```c
    len = get_length(i);
    *(arr+k) = (char*)malloc((len+1)*sizeof(char));
    for (j = len-1; j >= 0; j--)
    {
        *(*(arr+k)+j) = (char)(i % 10 + '0');
        i /= 10;
    }
    *(*(arr+k)+len)='\0';
```
还有一个易错点，涉及到数组下标问题，数组下标是从 0 开始，但是游戏是从 1 开始的。
# 复杂度
- 时间复杂度: 
$O(n)$
和输入的 n 成正比
- 空间复杂度: 
$O(n)$
和输入的 n 成正比
# Code
```C []

int get_length(int n)
{
    int len = 0;
    if(n == 0)
        return 1;
    while(n!=0)
    {
        len++;
        n /= 10;
    }
    return len;
}    

char ** fizzBuzz(int n, int* returnSize){
    *returnSize = n;
    char** arr = (char**)malloc(n*sizeof(char*));
    int i,j,k;
    int len;
    for(k = 0; k < n; k++)
    {
        i = k + 1;
        if(i%3==0 && i%5==0)
        {
            *(arr+k) = (char*)malloc(9*sizeof(char));
            sprintf(*(arr+k),"%s","FizzBuzz");
        }
        if(i%3==0 && i%5!=0)
        {
            *(arr+k) = (char*)malloc(5*sizeof(char));
            sprintf(*(arr+k),"%s","Fizz");
        }
         if(i%3!=0 && i%5==0)
        {
            *(arr+k) = (char*)malloc(5*sizeof(char));
            sprintf(*(arr+k),"%s","Buzz");
        }
        if(i%3!=0 && i%5!=0)
        {  
            len = get_length(i);
            *(arr+k) = (char*)malloc((len+1)*sizeof(char));
            //sprintf(*(arr+i),"%s",change_int_to_str(i));
            for (j = len-1; j >= 0; j--)
            {
                *(*(arr+k)+j) = (char)(i % 10 + '0');
                i /= 10;
            }
            *(*(arr+k)+len)='\0';
        }
    }   
    return arr; 
}

```
