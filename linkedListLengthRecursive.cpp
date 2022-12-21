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
int length(Node *head) {
    int i = 0;
    Node *newNode = head;
    if(newNode == NULL){
        return 0;
    }
    i += length(newNode->next) + 1;
    return i;
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

    cout << endl;
}

int main() {
    int t = 1;
    
    while (t--) {
        Node *head = takeinput();
        cout << length(head) << "\n";
    }
}