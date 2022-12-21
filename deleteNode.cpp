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

Node *deleteNode(Node *head, int pos){
    int j = 0;
	Node *newNode = NULL, *previous = NULL;
	newNode = head;

	if(pos == 0){
        head = head->next;
        delete newNode;
        return head;
    }

	while(newNode != NULL){
		if(j == pos){
            previous->next = newNode->next;
            delete newNode;
            return head;
        }
        j++;
        previous = newNode;
		newNode = newNode->next;
	}
    return head;
}

Node *deleteNode2(Node *head, int pos){
    if(head == NULL){
        return head;
    }
    if(pos == 0){
        return head->next;
    }
    Node* curr = head;
    int currPos = 0;

    while(curr != NULL && currPos < pos -1){
        ++currPos;
        curr = curr->next;
    }
    if(curr == NULL || curr->next == NULL){
        return head;
    }
    curr->next = curr->next->next;
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
    int position = 0;

	while (t--)
	{
		Node *head = takeinput();
		int pos = position;
		head = deleteNode(head, pos);
		print(head);
	}

	return 0;
}