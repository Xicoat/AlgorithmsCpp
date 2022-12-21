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

int length(Node *head)
{
    int i = 0;
	Node *newNode = NULL;
	newNode = head;

	while(newNode != NULL){
		i++;
		newNode = newNode->next;
	}
	return i;
}



Node *takeinput()
{
	int input[] = {3, 4, 5, 2, 6, 1, 9, -1};
	int i = 0;
	int data = input[i++];
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
	while (t--)
	{
		Node *head = takeinput();
		cout << length(head) << endl;
	}
	return 0;
}