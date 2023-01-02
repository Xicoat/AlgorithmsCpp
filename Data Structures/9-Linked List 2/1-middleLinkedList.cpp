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
void printLL(Node *head){
    while(head != NULL){
        cout << head->data << ", ";
        head = head->next;
    }
    cout << endl;
}

Node *midPoint(Node *head)
{
    printLL(head);
    if(head == NULL){
        return head;
    }

    int l = length(head);
    cout << "length: " << l << endl;
    int mid = l/2;
    cout << "mid: " << mid << endl; 
    if(l%2 != 0){
        mid++;
    }
    cout << "mid: " << mid << endl; 

    Node *newNode = head;
    for(int i = 1; i <= mid; i++){
        if(i == mid){
            return(newNode);
        }
        newNode = newNode->next;
    }
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

int main()
{
	int t = 1;
	while (t--)
	{
		Node *head = takeinput();
		Node *mid = midPoint(head);
		if (mid != NULL)
		{
			cout << mid->data;
		}
		cout << endl;
	}
	return 0;
}