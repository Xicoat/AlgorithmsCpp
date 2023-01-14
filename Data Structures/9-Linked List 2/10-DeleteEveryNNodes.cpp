/********************************************
 Delete every N nodes
You have been given a singly linked list of integers along with two integers, 'M,' and 'N.' Traverse the linked list such that you retain the 'M' nodes, then delete the next 'N' nodes. Continue the same until the end of the linked list.
To put it in other words, in the given linked list, you need to delete N nodes after every M nodes.

 *******************************************************/


#include <iostream>
using namespace std;


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

Node *takeinput()
{

    int input[] = {1, 2, 3, 4, 5, 6, 7, 8, -1};
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

bool isTail(Node *n){
    if(n->next == NULL){
        return true;
    }
    else return false;
}

Node *skipMdeleteN(Node *head, int M, int N)
{
    if(head == NULL || head->next == NULL){
        return head;
    }
	if(M == 0){
		return head = NULL;
	}

    Node *i = NULL;
    Node *j = NULL;
    i = head;
	int m = 1;
    
	while(true){
		print(head);
        while(m < M){
            if(isTail(i)) return head;
            i = i->next;
            m++;
        }
		m = 0;

        cout << "i " << i->data << endl;
        if(isTail(i)) return head;
        j = i->next;
		cout << "j " << j->data << endl;
        int n = 0;
        while(n < N){
            deleteNode(i, j);
            if(isTail(i)) return head;
            j = i->next;
            n++;
        }
    }
}



int main()
{
	int t = 1;
	while (t--)
	{
		Node *head = takeinput();
		int m = 2, n = 3;
		head = skipMdeleteN(head, m, n);
		print(head);
	}
	return 0;
}