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

// Function to delete the node at the end
void deleteAtEnd() {
    if (head == NULL) {
        cout << "List is already empty!" << endl;
        return;
    }

    Node *temp = head;

    // If there's only one node
    if (temp->next == NULL) {
        delete temp;
        head = NULL;
        cout << "Last node deleted. List is now empty." << endl;
        return;
    }

    // Traverse to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    delete temp;
    cout << "Node deleted from the end." << endl;
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

    // Delete a node from the end
    deleteAtEnd();
    print(); // Print after deletion

    return 0;
}
