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

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2){

    Node *pointer1 = NULL, *pointer2 = NULL;
    if(head2 == NULL){
        return head1; 
    } else if(head1 == NULL){return head2;}

    if(head1->data > head2->data){
        pointer2 = head2;
        head2 = head2->next;
        pointer2->next = head1;
        head1 = pointer2;
    }
    Node *newNode = head1;

    print(head1);
    print(head2);

    while(head1->next != NULL){
        cout << "head1:  ";
        print(head1);
        cout << "head2:  ";
        print(head2);
        cout << "head1->data: " << head1->data << endl;
        cout << "head2->data: " << head2->data << endl;
        if((head1->next)->data < head2->data){
            head1 = head1->next;
        } else {
            pointer2 = head2;
            head2 = head2->next;
            pointer2->next = head1->next;
            head1->next = pointer2;
            head1 = head1->next;
        }

    }
    head1->next = head2;
    print(head1);
    return newNode;
}

Node *mergeTwoSortedLinkedLists3(Node *head1, Node *head2){
    if(head1 == NULL) {
        return head2;
    }
    if(head2 == NULL) {
        return head1;
    }
    Node *newHead = NULL, *newTail = NULL;

    if(head1->data < head2->data){
        newHead = head1;
        newTail = head1;
        head1 = head1->next;
    }
    else {
        newHead = head2;
        newTail = head2;
        head2 = head2->next;
    }
    while(head1 != NULL  && head2 != NULL){
        if(head1->data < head2->data){
            newTail->next = head1;
            newTail = newTail->next;
            head1 = head1->next;
        }
        else {
            newTail->next = head2;
            newTail = newTail->next;
            head2 = head2->next;
        }
    }

    if (head1 != NULL) {
        newTail->next = head1;
    }
    if (head2 != NULL) {
        newTail->next = head2;
    }
    return newHead;
}



Node *takeinput(int input[])
{
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
    int input1[] = {10, 10, 22, -1};
    int input2[] = {3, 8, 8, 36, -1};

	while (t--)
	{
		Node *head1 = takeinput(input1);
		Node *head2 = takeinput(input2);
		Node *head3 = mergeTwoSortedLinkedLists3(head1, head2);
		print(head3);
	}
	return 0;
}