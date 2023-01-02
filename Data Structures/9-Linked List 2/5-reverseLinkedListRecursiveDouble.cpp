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

Node *reverseLinkedListRec(Node *head)
{
    if (head == NULL || head->next == NULL) {
    return head;
    }

    Node *smallAns = reverseLinkedListRec(head->next);
    Node *temp = smallAns;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head;
    head->next = NULL;
    return smallAns;
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

int main()
{
	int t = 1;
	while (t--)
	{
		Node *head = takeinput();
		head = reverseLinkedListRec(head);
		print(head);
	}

	return 0;
}