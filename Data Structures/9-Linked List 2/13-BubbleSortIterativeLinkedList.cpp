//bubble sort iterative

using namespace std;
#include <iostream>


class Node{
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
	int input[] = {-1};
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

Node* up(Node* previous, Node* current){
    
    if(current == NULL && current->next == NULL){
        return current;
    }
    

    Node *nextNode = current->next;
    Node *temp = current;

    current->next = nextNode->next;
    if (previous != NULL){
        previous->next = nextNode;
    }
    nextNode->next = current;

    return nextNode;
}

int len(Node* head){
    if(head == 0){
        return 0;
    }
    int i = 1;
    while(head != 0 && head->next != NULL){
        head = head->next;
        i++;
    }
    return i;
}


Node *bubbleSort(Node *head)
{
    if (head == NULL){
        return head;
    }

    int n = len(head); 
    int i = 1;

    for(int i = 1; i <= n; i++){
        Node* previous = NULL;
        Node* current = head;
        while(current->next != NULL){
            if(current->data > (current->next)->data){
                if(previous == NULL){
                    head = up(previous, current);
                    previous = head;
                }
                else{
                    up(previous, current);
                    previous = previous->next;
                }
            }
            else{
                previous = current;
                current = current->next;
            }
        }
    }
    return head;
}



int main()
{
	Node *head = takeinput();
    print(head);
	head = bubbleSort(head);
	print(head);
}