#include <iostream>
#include <stdio.h>
using namespace std;

typedef struct _node{
	int data;
	struct _node* next;
}Node;
//设计一个算法，删除带头结点的单链表L中所有值为x的结点。


void del_x(Node*& L, int x){
	Node* node1 = L;
	Node* node2 = L;
	while(node2 = node1->next)
	{
		if(node2->data == x)
		{
			node1->next = node2->next;
			delete node2;
			node1 = node1->next;
		}
		else
			node1 = node1->next;	
	}
}

void printList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << "\n";
}

int main() {
    Node* head = new Node{1, new Node{2, new Node{3, new Node{2, new Node{1, nullptr}}}}};
    
    std::cout << "Original list: ";
    printList(head);

    del_x(head, 2);

    std::cout << "List after deleting 2: ";
    printList(head);
    
    return 0;
}

