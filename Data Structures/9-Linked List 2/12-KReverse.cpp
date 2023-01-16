/*******************************
 * kReverse
Send Feedback
Given a singly linked list of integers, reverse the nodes of the linked list 'k' at a time and return its modified list.
 'k' is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of 'k,' then left-out nodes, in the end, should be reversed as well.
 ********************************/

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

Node *takeinput()
{
	int input[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, -1};
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

Node *reverse(Node *start, Node *end){
	//cout << end->data;
    Node *current = start;
    Node *prev = NULL;
    Node *next = NULL;

    while(current != NULL){
		cout << "current: " << current->data << " end: " << end->data << endl;
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
		if(current == end){
			break;
		}
    }
    start = prev;
    return start;
}


Node *kReverse(Node *head, int k){
	if (head == NULL){
		return head;
	}
	
	Node* end = head;
	Node* start = head;
	int i = 1;
	while(end != NULL){
		cout << i << endl;
		if (i == k){
			cout << "start: " << start->data << " end: " << end->data << endl;
			start = end->next;
			end = end->next;
			i = 1;
			continue;
		}
		end = end->next;
		i++;
	}
	cout << end->data << endl;
}

Node *kReverse2(Node *head, int k)
{
	if (head == NULL){
		return head;
	}
	Node * end = head;
	for (int i = 1; i < k; i++){
		cout << "i " << i << endl;
		cout << end->data << endl;
		if (end->next == NULL){
			break;
		}
		end = end->next;
	}
	head = reverse(head, end);
	return head;
}

int main()
{
	int t = 1;

	while (t--)
	{
		Node *head = takeinput();
		int k = 3;
		head = kReverse(head, k);
		print(head);
	}
	
	return 0;
}