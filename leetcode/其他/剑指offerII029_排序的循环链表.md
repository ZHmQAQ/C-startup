> Problem: [剑指 Offer II 029. 排序的循环链表](https://leetcode.cn/problems/4ueAj6/description/)

[TOC]

# 思路
遍历循环链表，维护两个邻接结点指针，如果结点数据 左<=目标<=右，则插入；如果结点数据 左>右，说明此时刚好遍历到头尾结点交界处，此时如果 左<=目标 or 右>=目标，说明目标元素比最大的还要大，或者比最小的还要小，则直接在这个位置插入。

# 解题方法
核心是这个do while 循环
```cpp
        do{
            if(node->val < insertVal && node->next->val >= insertVal)
            {
            }
            if(node->val > node->next->val && (insertVal >= node->val || insertVal <= node->next->val))
            {
            }
            node = node->next;
        }
        while(node != head);
```
同时用flag变量记录是否经过插入。如果循环执行完毕都没插入，说明每个元素是相等的，直接在任意位置执行插入操作即可。

# 复杂度
- 时间复杂度: 
 $O(n)$

- 空间复杂度: 
 $O(1)$

# Code
```C++ []

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        int flag = 0;
        Node* node = head;
        Node* newnode = new Node;
        newnode->next = nullptr;
        newnode->val = insertVal;
        if(head == nullptr)
        {
            newnode->next = newnode;
            return newnode;
        }
        if(node->next == node)
        {
            node->next = newnode;
            newnode->next = node;
            return head;
        }

        do{
            if(node->val < insertVal && node->next->val >= insertVal)
            {
                Node* temp = node->next;
                node->next = newnode;
                newnode->next = temp;
                flag = 1;
                break;
            }
            if(node->val > node->next->val && (insertVal >= node->val || insertVal <= node->next->val))
            {
                Node* temp = node->next;
                node->next = newnode;
                newnode->next = temp;
                flag = 1;
                break;
            }
            node = node->next;
        }
        while(node != head);
    if(flag == 0)
    {
    Node* temp = node->next;
    node->next = newnode;
    newnode->next = temp;
    }
    return head;
    }
};
```
