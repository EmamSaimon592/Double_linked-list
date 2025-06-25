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

// Function to insert a new node at the end...
void insertAtEnd(int n){
    Node *newNode = new Node;
    newNode -> data = n;
    newNode -> next = NULL;
    newNode -> prev = NULL;

    if(head == NULL){
        head = newNode;
    }
    else {
      Node *temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
       }
        temp -> next = newNode;
        newNode -> prev = temp;  
    }
    
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

    insertAtEnd(60);
    print();

    return 0;
}

// run this code then you can get output
