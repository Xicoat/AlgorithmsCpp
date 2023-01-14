/*************************
 * Swap two Nodes of LL
Send Feedback
You have been given a singly linked list of integers along with two integers, 'i,' and 'j.' Swap the nodes that are present at the 'i-th' and 'j-th' positions.

****************************************/

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
	int input[] = {70, 80, 90, 25, 65, 85, 90, -1};
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

void deleteNode(Node *prev, Node *current){
	prev->next = current->next;
	delete(current);
}

Node *swapNodes(Node *head, int i, int j){

		

	if (i > j) {
		int temp = i;
		i = j;
		j = temp;
	}

	Node *prev1 = NULL;
	Node *current1 = head;
	Node *prev2 = NULL;
	Node *current2 = head;

	int ii = 0;
	while(ii < i){
		prev1 = current1;
		current1 = current1->next;
		ii++;
	}

	int jj = 0;
	while(jj < j){
		prev2 = current2;
		current2 = current2->next;
		jj++;
	}

	Node* temp = current2->next;
	if(prev1 == NULL){
		head = current2;
	} else {
		prev1->next = current2;
	}
	prev2->next = current1;
	current2->next = current1->next;
	current1->next = temp;
	

	return head;
}

int main()
{
	int t = 1;
	while (t--)
	{
		int i = 5, j = 6;
		Node *head = takeinput();
		head = swapNodes(head, i, j);
		print(head);
	}
	return 0;
}