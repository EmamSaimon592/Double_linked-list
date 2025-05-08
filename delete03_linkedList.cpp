#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
};

Node *head = NULL;

// Function to insert a new node at the beginning
void insert(int n) {
    Node *newNode = new Node;
    newNode->data = n;
    newNode->next = head;
    newNode->prev = NULL;

    if (head != NULL) {
        head->prev = newNode;
    }

    head = newNode;
}

// Function to delete a node at a specific position (1-based)
void deleteAtPosition(int position) {
    if (head == NULL || position <= 0) {
        cout << "Invalid position or list is empty." << endl;
        return;
    }

    Node *temp = head;

    // If deleting the first node
    if (position == 1) {
        head = temp->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        delete temp;
        cout << "Node at position 1 deleted." << endl;
        return;
    }

    // Traverse to the desired position
    for (int i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }

    // If position is greater than the number of nodes
    if (temp == NULL) {
        cout << "Position exceeds list length." << endl;
        return;
    }

    // Adjust pointers to remove temp
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    delete temp;
    cout << "Node at position " << position << " deleted." << endl;
}

// Function to print the list
void print() {
    cout << "Data elements in a Doubly Linked List are:\n";
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    print();

    // Delete node at position 3
    deleteAtPosition(3);
    print();

    return 0;
}
