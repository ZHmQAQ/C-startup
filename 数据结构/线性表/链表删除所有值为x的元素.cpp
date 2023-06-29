#include <iostream>
#include <stdio.h>
using namespace std;

//设计一个递归算法，删除不带头结点的单链表L中所有值为x的结点。
class Solution{
public:
typedef struct _node{
	int data;
	struct _node* next;
}Node;
public:
	void del_x(Node*& L, int x){
		if(!L)
			return;
		else
		{
			if(L->data == x){			
				Node* tmp= L;
				L = L->next;
				delete tmp;
				del_x(L,x);
			}
			else
				del_x(L->next,x);
		}
	}
}; 

//class Solution{
//public:
//    typedef struct _node{
//        int data;
//        struct _node* next;
//    } Node;
//
//public:
//    Node* del_x(Node* L, int x){
//        if(!L){
//            return nullptr;
//        }
//
//        if(L->data == x){
//            Node* nextNode = L->next;
//            delete L;
//            return del_x(nextNode, x);
//        }else{
//            L->next = del_x(L->next, x);
//            return L;
//        }
//    }
//};


int main(){
    Solution solution;
    
    //创建链表
    Solution::Node* L = new Solution::Node();
    Solution::Node* temp = L;
    for(int i = 0; i < 10; ++i){
        temp->data = i;
        if(i < 9){
            temp->next = new Solution::Node();
            temp = temp->next;
        }else{
            temp->next = nullptr;
        }
    }

    //删除值为5的节点
    solution.del_x(L, 5);

    //打印链表
    temp = L;
    while(temp != nullptr){
        std::cout << temp->data << " ";
        temp = temp->next;
    }

    //清理链表
    while(L != nullptr){
        temp = L;
        L = L->next;
        delete temp;
    }

    return 0;
}
