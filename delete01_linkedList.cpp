
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

// Function to delete the node at the beginning
void deleteAtBeginning() {
    if (head == NULL) {
        cout << "List is already empty!" << endl;
        return;
    }

    Node *temp = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }

    delete temp;
    cout << "Node deleted from the beginning." << endl;
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

    // Delete a node from the beginning
    deleteAtBeginning();
    print(); // Print after deletion

    return 0;
}


//Run this code you will get output 

