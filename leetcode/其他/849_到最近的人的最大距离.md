> Problem: [849. 到最近的人的最大距离](https://leetcode.cn/problems/maximize-distance-to-closest-person/description/)

[TOC]

# 思路
最基本思路：动态规划，然后这道题因为没有什么特殊限制条件，其实就是记录一个 总体最大值 和 当前最大值 进行比较即可。之后返回 max / 2.
```c
    maxval = max(maxval,currentmax)
```
但这道题有两个坑：

第一个坑是，返回值并不是 max / 2，而是需要向上取整，例如，如果 max = 3，也就是最多有三个空位连续分布，坐在最中间的位置时，最大间距应该是 2，因此得出返回值公式：
```c
    return (maxval + 1) / 2
```

第二个坑是，左右两侧属于特殊情况，在左右两侧有空间的时候，我们会选择贴墙，来让距离最大化，因此再建立两个变量来计算最左边和最右边的特殊情况：
```c
int maxleft = 0; int maxright = 0;
while(seats[maxleft++]!=1);
while(seats[seatsSize - 1 -(maxright++)]!=1);
```
最终的返回值：
```c
max = max((max+1)/2,max(maxleft-1,maxright-1));
```

# 解题方法
动态规划。扫一遍数组，更新最大间隔，然后 向上取整除以二。
再讨论左右两侧特殊情况。
最后返回这三个最大值中的最大值。

# 复杂度
- 时间复杂度: 
$O(n)$
仅需一次遍历（三次）

- 空间复杂度: 
$O(1)$
原地算法

# Code
```C []

#define max(a,b) ((a) > (b) ? (a) : (b))
int maxDistToClosest(int* seats, int seatsSize){
    int max = 0;
    int curr = 0;
    for(int i = 0; i < seatsSize; i++){
        if(seats[i] == 0)
            curr++;
        else
            curr = 0;
        max = max(max,curr);
    }
    int maxleft = 0; int maxright = 0;
    while(seats[maxleft++]!=1);
    while(seats[seatsSize - 1 -(maxright++)]!=1);
    max = max((max+1)/2,max(maxleft-1,maxright-1));
    return max;
}
```
