> Problem: [剑指 Offer 22. 链表中倒数第k个节点](https://leetcode.cn/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/description/)

[TOC]

# 思路
首先我们要得到表长 n，然后再访问第 n-k 个元素即可。
如果可以改变链表，可以尝试每次访问结点之后将结点指针从下一个元素地址改成上一个元素的地址。但是不能改变。


# 解题方法
定义一个求表长的函数`listlength(struct ListNode* p)`，作用是从头扫一遍，遇到 NULL 就停止。
获得表长之后，从头扫一遍，到第 n-k 个元素就停止。

# 复杂度
- 时间复杂度: 
$O(n)$

- 空间复杂度: 
$O(n)$

# Code
```C []
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* getKthFromEnd(struct ListNode* head, int k)
{
    int len = ListLenth(head);
    for(int i = 0;i<len-k;i++)
        head = head->next;
    return head;
}

int ListLenth(struct ListNode* p)
{
    int count = 0;
    while(p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}
```