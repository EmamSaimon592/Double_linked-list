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

// Function to insert a new node at any position...
void insertAtPosition(int pos , int n){
    Node * newNode = new Node;
    newNode -> data = n;
    if(pos == 1){
        newNode -> next = head;
        newNode -> prev = NULL;
        if(head != NULL){
            head -> prev = newNode;
        }
        head = newNode;
        return;
    }

    Node *temp = head;
    for(int i =1; i<pos -1 && temp!= NULL; i++){
        temp = temp -> next;
    }
    if(temp == NULL){
        cout<<"position"<< pos <<"does not exist in the list."<<endl;
        return;
    }
    newNode -> next = temp -> next;
    newNode -> prev = temp;
    temp -> next -> prev = newNode;
    temp -> next = newNode;

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

   insertAtPosition(4, 35); //50 -> 40 -> 30 -> 35 -> 20 -> 10 -> NULL
    print();

    return 0;
}
