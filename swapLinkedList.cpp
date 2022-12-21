/*AppendLastNToFirst
You have been given a singly linked list of integers along with an 
integer 'N'. Write a function to append the last 'N' nodes towards 
the front of the singly linked list and returns the new head to the 
list.*/

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

int length(Node *head) {
    int i = 0;
    Node *newNode = head;
    if(newNode == NULL){
        return 0;
    }
    i += length(newNode->next) + 1;
    return i;
}

Node *appendLastNToFirst(Node *head, int n)
{
	cout << "swapPoint: " << n << endl;
    int l = length(head);
	if(l < 1){
		return head;
	}
	cout << "length: " << l << endl; 
	Node *tail = NULL, *swapNode = NULL;
    Node *newNode = NULL;
    newNode = head;

    for(int i = 1; i <= l; i++){
		if(i == (l-n)){
			swapNode = newNode;
			cout << "Swap Node: "<< swapNode->data << endl;
		}
		if(i == l){
			tail = newNode;
			cout << "Tail Node: "<< tail->data << endl;
		}
		newNode = newNode->next;
    }
    
	tail->next = head;
	head = swapNode->next;
	cout << "head: " << head->data << endl;
	swapNode->next = NULL;
	cout << "swapNode: " << swapNode->next << endl;
	return head;
    
}


Node *takeinput()
{
    int input[] = {4, 4, 7, 8, 3, 36, 8, 17, 26, 10, 7, -1};
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
    int swap = 7;
	while (t--)
	{
		Node *head = takeinput();
		int n;
		n = swap;
		head = appendLastNToFirst(head, n);
		print(head);
	}
	return 0;
}
