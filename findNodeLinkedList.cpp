/*You have been given a singly linked list of integers. Write a 
function that returns the index/position of integer data denoted 
by 'N' (if it exists). Return -1 otherwise.*/

#include <iostream>

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

using namespace std;



int findNode(Node *head, int n){
    int ex = 1;
	if(head == NULL){
        return -1;
    }

    if(head->data == n){
        Node *newNode = NULL;
        return 0;
    }

    ex = findNode(head->next, n);

    if(ex == -1){
        return -1;
    } else {ex++;}

    return ex;
}

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

int main()
{
    int t = 1;
    int value = 50;

	while (t--)
	{
		Node *head = takeinput();
		int val;
		val = value;
		cout << findNode(head, val) << endl;
	}
}