//The header file
#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class ListADT {
private:
    Node* head;  // Head pointer

public:
    ListADT(); // Constructor
    void insertAscending(int value);
    static ListADT mergeLists(ListADT& list1, ListADT& list2);
    void display();
};

#endif
