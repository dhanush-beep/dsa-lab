//To make a list adt 
#include "list.h"
#include <iostream>
using namespace std;

// Constructor to initialize head pointer
ListADT::ListADT() {
    head = nullptr;
}

// Insert node in ascending order
void ListADT::insertAscending(int value) {
    Node* newNode = new Node(value);
    if (!head || head->data >= value) {
        newNode->next = head;
        head = newNode;
        return;
    }
    
    Node* temp = head;
    while (temp->next && temp->next->data < value) {
        temp = temp->next;
    }
    
    newNode->next = temp->next;
    temp->next = newNode;
}

// Merge two sorted lists into a new sorted list 
ListADT ListADT::mergeLists(ListADT& list1, ListADT& list2) {
    ListADT mergedList;
    Node* head1 = list1.head;
    Node* head2 = list2.head;
    Node* mergedTail = nullptr; // Tail pointer for merged list

    while (head1 && head2) {
        Node* newNode;
        if (head1->data <= head2->data) {
            newNode = new Node(head1->data);
            head1 = head1->next;
        } else {
            newNode = new Node(head2->data);
            head2 = head2->next;
        }

        if (!mergedList.head) {
            mergedList.head = newNode;
            mergedTail = newNode;
        } else {
            mergedTail->next = newNode;
            mergedTail = mergedTail->next;
        }
    }

    // Append remaining elements from list1
    while (head1) {
        Node* newNode = new Node(head1->data);
        mergedTail->next = newNode;
        mergedTail = newNode;
        head1 = head1->next;
    }

    // Append remaining elements from list2
    while (head2) {
        Node* newNode = new Node(head2->data);
        mergedTail->next = newNode;
        mergedTail = newNode;
        head2 = head2->next;
    }

    return mergedList;
}

// Display the list safely
void ListADT::display() {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
