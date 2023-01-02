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

Node *deleteNodeRec(Node *head, int pos) {
    int i = pos;
	if(head == NULL){
        return head;
    }

    if(i == 0){
        head = head->next;
        return head;
    }

    if(i == 1){
        Node *newNode = NULL;
        newNode = head->next;
        if(head->next == NULL){
            return head;
        }
        head->next = newNode->next;
        return head;
    }

    deleteNodeRec(head->next, --i);
    return head;
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
    int position = 7;

	while (t--)
	{
		Node *head = takeinput();
		int pos = position;
		head = deleteNodeRec(head, pos);
		print(head);
	}

	return 0;
}