#include <iostream>

class Node {
    public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

using namespace std;

Node* insertNode(Node *head, int i, int data) {

    if(head == NULL){
        return head;
    }

    if(i == 0){
        Node *newNode = new Node(data);
        newNode->next = head;

        head = newNode;
        return head;
    }

    if(i == 1){
        Node *newNode = new Node(data);
        newNode->next = head->next;

        head->next = newNode;
        return head;
    }

    insertNode(head->next, --i, data);
    return head;
}

Node *takeinput() {
    int input[] = {3, 4, 5, 2, 6, 1, 9, -1};
	int i = 0;

    int data;
    data = input[i++];
    Node *head = NULL, *tail = NULL;
    while (data != -1) {
        Node *newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
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

    cout << "\n";
}

int main() {
    int t = 1;
    int position = 2;
    int insertData = 100;

    while (t--) {
        Node *head = takeinput();
        int pos = position, data = insertData;
        head = insertNode(head, pos, data);
        print(head);
    }
}