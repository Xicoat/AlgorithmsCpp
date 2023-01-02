/*You have been given a head to a singly linked list of integers. 
Write a function check to whether the list given is a 'Palindrome' or not.*/

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

Node *reverse(Node *head) {
    Node *prev = NULL, *curr = head, *next = NULL;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return(prev);
}

void printLL(Node *head){
    while(head != NULL){
        cout << head->data << ", ";
        head = head->next;
    }
    cout << endl;
}

bool isPalindrome(Node *head)
{
    int l = length(head);
    Node *head1 = head, *tail1 = NULL;
    Node *head2 = NULL;

    int end1 = l/2;
    int begin2 = 0;
    if(l%2 == 0){
        begin2 = end1 + 1;
    } else {begin2 = end1 + 2;}

    Node *newNode = head;
    for(int i = 1; i <= l; i++){
        if(i == end1){
            tail1 = newNode;
            cout <<" tail1: " << tail1->data << endl;
        }
        if(i == begin2){
            head2 = newNode;
            tail1->next = NULL;
            cout << "head2: " << head2->data << endl;
            break;
        }
        newNode = newNode->next;
    }

    cout << "head1: " << endl;
    printLL(head1);
    cout << "head2: " << endl;
    printLL(head2);
    
    head2 = reverse(head2);
    cout << "head2 reversed: " << endl;
    printLL(head2);
    cout << head2->data << endl;

    while(head1 != NULL && head2 != NULL){
        if(head1->data != head2->data){
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return true;
}

Node *takeinput()
{
    int input[] = {2, 3, 8, 7, 3, 2, -1};
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
		bool ans = isPalindrome(head);

		if (ans) cout << "true";
		else cout << "false";

		cout << endl;
	}

	return 0;
}