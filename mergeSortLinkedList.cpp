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

int length(Node *head) {
    int i = 0;
    Node *newNode = head;
    if(newNode == NULL){
        return 0;
    }
    i += length(newNode->next) + 1;
    return i;
}


Node *midPoint(Node *head)
{
    if(head == NULL){
        return head;
    }

    int l = length(head);
    int mid = l/2;

    Node *newNode = head;
    for(int i = 1; i <= mid; i++){
        if(i == mid){
            return(newNode);
        }
        newNode = newNode->next;
    }
}

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2){
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

//*********************************************//
Node *mergeSort(Node *head)
{
    if ((head == NULL) || (head->next == NULL)) {
        return head;
    }

    Node *head1 = NULL;
    Node *head2 = NULL;

	Node *midPrev = midPoint(head);
    cout << "midPrev: " << midPrev->data << endl;
    cout << "(midPrev->next)->data: " << (midPrev->next)->data << endl;

	Node *mid = NULL;
    if(midPrev == NULL){
        return midPrev;
    }
    mid = midPrev->next;
	midPrev->next = NULL;
    head1 = head;
    head2 = mid;
	
	//cout << "head1: " << head1->data << endl;
    print(head1);
	//cout << "head2: " << head2->data << endl;
    print(head2);

    if(head1->next != NULL){
        head1 = mergeSort(head1);
    }
    if(head2->next != NULL){
        head2 = mergeSort(head2);
    }

    head = mergeTwoSortedLinkedLists(head1, head2);

    return head;
}

Node *takeinput()
{
	int input[] = {7, 5, 10, 14, 10, 16, 3, 16, 0, 1, 10, -1};
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



int main()
{
	int t = 1;
	while (t--)
	{
		Node *head = takeinput();
		head = mergeSort(head);
		print(head);
	}

	return 0;
}