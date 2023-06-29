#include <iostream>
#include <stdio.h>
using namespace std;

typedef struct _node{
	int data;
	struct _node* next;
}Node;
//设计一个算法，删除带头结点的单链表L中的最小值


void del_x(Node*& L){
	Node* node = L;
	Node* minnode = L;
	if(!L->next)
		return;
	while(node->next)
	{
		if(node->next->data < minnode->next->data)
		{
			minnode = node;
		}
		node = node->next;	
	}

	Node* temp = minnode->next;
	minnode->next = temp->next;
	delete temp;
	
}

void printList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << "\n";
}


int main() {
    Node* head = new Node{0, new Node{1, new Node{2, new Node{3, new Node{2, new Node{-4, nullptr}}}}}};
    
    std::cout << "Original list: ";
    printList(head->next);

    del_x(head);

    std::cout << "List after deleting min: ";
    printList(head->next);
    
    return 0;
}





