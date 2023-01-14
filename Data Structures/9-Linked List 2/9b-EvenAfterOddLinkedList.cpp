/***************************************
 For a given singly linked list of integers, arrange the elements such that all the even numbers are placed after the odd numbers. The relative order of the odd and even terms should remain unchanged.

**********************************************/


#include <iostream>
using namespace std;



class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};


Node *takeinput()
{
	int input[] = {4, 2, 7, 8, 3, 36, -1};
	int i = 0;

	int data;
	data = input[i++];
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		data = input[i++];
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

Node *evenAfterOdd(Node *head){
    if (head == NULL){
        return head;
    }

    Node *evenHead = NULL, *oddHead = NULL, *evenTail = NULL, *oddTail = NULL;

    while (head != NULL){
        if(head->data % 2 == 0) {
            if (evenHead == NULL){
                evenHead = head;
                evenTail = head;
            }
            else {
                evenTail->next = head;
                evenTail = evenTail->next;
            }
        }
        else {
            if(oddHead == NULL){
                oddHead = head;
                oddTail = head;
            }
            else {
                oddTail->next = head;
                oddTail = oddTail->next;
            }
        }
        head = head->next;
    }
    if(oddHead == NULL){
        return evenHead;
    }
    else {
        oddTail->next = evenHead;
    }
    if (evenHead != NULL) {
        evenTail->next = NULL;
    }
    return oddHead;
}

int main()
{
	int t = 1;
	while (t--)
	{
		Node *head = takeinput();
		head = evenAfterOdd(head);
		print(head);
	}
	return 0;
}