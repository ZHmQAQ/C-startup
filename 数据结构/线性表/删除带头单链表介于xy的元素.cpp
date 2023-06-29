#include <iostream>
#include <stdio.h>
using namespace std;

typedef struct _node{
	int data;
	struct _node* next;
}Node;
//设计一个算法，删除带头结点的单链表所有介于x和y的值 



void del_x(Node*& L, int min, int max){
	Node* node = L;
	if(!L->next)
		return;
	while(node->next)
	{
		if(node->next->data > min && node->next->data < max)
		{
			Node* temp = node->next;
			node->next = node->next->next;
			delete temp;
		}
		else
			node = node->next;
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
    Node* head = new Node{0, nullptr};  // create head node
    Node* current = head;

    // Populate linked list with some values
    for(int i = 1; i <= 10; i++) {
        Node* node = new Node{i, nullptr};
        current->next = node;
        current = node;
    }

    std::cout << "Original List:\n";
    printList(head);

    del_x(head, 3, 7);  // Delete nodes with data between 3 and 7

    std::cout << "Modified List:\n";
    printList(head);

    // Delete remaining nodes
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}




