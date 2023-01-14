#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

Node* reverseLL_3(Node *head) {
	if(head == NULL || head -> next == NULL) {
		return head;
	}

	Node *smallAns = reverseLL_3(head -> next);

	Node *tail = head -> next;
	tail -> next = head;
	head -> next = NULL;
	return smallAns;
}

class Pair {
	public :
		
			Node *head;
			Node *tail;
};

Node *takeInput_Better()
{
    int input[] = {18, 21, 9, 4, 10, 15, -1};
	int i = 0;
    
	int data;
	data = input[i++];

	Node *head = NULL;
	Node *tail = NULL;
	while(data != -1) {
		Node *newNode = new Node(data);
		if(head == NULL) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail -> next = newNode;
			tail = tail -> next;
			// OR
			// tail = newNode;
		}
		data = input[i++];
	}
	return head;
}

void print(Node *head) {
	while(head != NULL) {
		cout << head -> data << " ";
		head = head -> next;
	}
	cout << endl;
}

int main() {
	Node *head = takeInput_Better();
    print(head);
	head = reverseLL_3(head);
	print(head);
}
