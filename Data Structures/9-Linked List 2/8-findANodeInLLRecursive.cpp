/*********************
Given a singly linked list of integers and an integer n, find and return the index for the first occurrence of 'n' in the linked list. -1 otherwise.
Follow a recursive approach to solve this.
Note :
Assume that the Indexing for the linked list always starts from 0.
**********************/

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
    int input[] = {18, 21, 9, 4, 10, 15, -1};
	int i = 0;

	int data;
	data = input[i++];
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		data = input[i++];
	}
	return head;
}

void print(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


int findNodeRec(Node *head, int n){
	//Write your code here
    cout << head->data << endl;
    int position = 0;

    if(head == NULL) {
        return -1;
    }
    else if (head->data == n){
        return 0;
    }
    position = findNodeRec(head->next, n);
    if(position == -1){
        return -1;
    }
    return position += 1;
}

int main()
{
    int find = 10;
	int t = 1;
	while (t--)
	{
		Node *head = takeinput();
		int val;
		val = find;
		cout << findNodeRec(head, val) << endl;
	}
}