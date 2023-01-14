#include <iostream>
using namespace std;

class Node {
   public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};


Node *takeInput()
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

void print(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}



Node *reverseLinkedList(Node *head) {
    // Write your code here
    cout << "Linked Function" << endl; 
    print(head);

    Node *current = head;
    Node *previous = NULL;
    Node *next = current->next;

    while(current != NULL){
        current->next = previous;
        previous = current;
        current = next;
        if(current != NULL){
            next = current->next;
        }
        print(previous);
    }
    print(previous);
    return previous;
}

Node *reverseLinkedList2(Node *head) {
    Node *currentNode = head;
    Node *previousNode = NULL;

    while (currentNode != NULL) {
        Node *nextNode = currentNode->next;
        currentNode->next = previousNode;
        previousNode = currentNode;
        currentNode = nextNode;
    }
    head = previousNode;
    return head;
}




int main() {
    int t = 1;

    while (t--) {
        Node *head = takeInput();
        print(head);
        head = reverseLinkedList(head);
        print(head);
    }

    return 0;
}