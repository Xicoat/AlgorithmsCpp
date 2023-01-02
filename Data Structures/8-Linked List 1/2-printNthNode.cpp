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

void printIthNode(Node *head, int i)
{
    int j = 0;
	Node *newNode = NULL;
	newNode = head;

	while(newNode != NULL){
		if(j == i){
            cout << newNode->data ;
            return;
        }
        j++;
		newNode = newNode->next;
	}
}

Node *takeinput()
{
    int input[] = {3, 4, 5, 2, 6, 1, 9, -1};
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
    int position = 3;
	while (t--)
	{
		Node *head = takeinput();
		int pos;
		pos = position;
		printIthNode(head, pos);
		cout << endl;
	}
	return 0;
}