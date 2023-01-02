/*You have been given a singly linked list of integers where 
the elements are sorted in ascending order. Write a function 
that removes the consecutive duplicate values such that the 
given list only contains unique elements and returns the head 
to the updated list.*/

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


Node *removeDuplicates(Node *head)
{
    if(head == NULL){
        return head;
    }
    Node * tester = NULL;
    for(tester = head; tester->next != NULL; ){
        if(tester->data == (tester->next)->data){
            tester->next = (tester->next)->next;
        } else {tester = tester->next;}
    }
    return head;
}



Node *takeinput()
{
    int input[] = {1, 1, 1, 2, 3, 3, 4, 5, 5, 6, 7, 7, 7, 7, 7, 8, -1};
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
		head = removeDuplicates(head);
		print(head);
	}
	return 0;
}