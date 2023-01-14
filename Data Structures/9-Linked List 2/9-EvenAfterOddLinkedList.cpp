/***************************************
 For a given singly linked list of integers, arrange the elements such that all the even numbers are placed after the odd numbers. The relative order of the odd and even terms should remain unchanged.

**********************************************/


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
	int input[] = {4, 2, 7, 8, 3, 36, -1};
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

Node *insertNextNode(Node *current, int value){
	Node *newNode = new Node(current->data);
	newNode->next = current->next;
	current->data = value;
	current->next = newNode;
	return current;
}

Node *evenAfterOdd(Node *head){
	// current es el nodo que se esta evaluando.
	Node *current = head;

	while(current != NULL){
		Node *prev = NULL;
		Node *idx = current;

		// Si current es par entonces se detiene y busca impares
		if((current->data % 2) == 0){
			// mientras idx sea par continua avanzando
			while((idx->data % 2) == 0){
				prev = idx;
				idx = idx->next;
				// si idx llega al final sin encontrar impares termina
				// y regresa head
				if(idx->next == NULL){
					return head;
				}
			}

			// si llega aqui quiere decir que encontró un impar
			// guardar el valor del impar y de current
			int currentValue = current->data;
			int idxValue = idx->data;
			// insertar un nodo frente a current con el valor de current;
			insertNextNode(current, idxValue);
			// borrar nodo idx
			deleteNode(prev, idx);			
		}
		current = current->next;
	}
	return head;
}

int main()
{
	int t = 1;
	while (t--)
	{
		Node *head = takeinput();
		head = evenAfterOdd(head);
		print(head);
	}
	return 0;
}