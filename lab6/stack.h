#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
};

class Stack {
private:
    Node* top;
public:
    Stack() { top = nullptr; }

    bool isEmpty() { return top == nullptr; }

    void push(char data) {
        Node* newNode = new Node();
        if (!newNode) {
            cout << "Memory allocation failed\n";
            return;
        }
        newNode->data = data;
        newNode->next = top;
        top = newNode;
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack underflow\n";
            return '\0';
        }
        Node* temp = top;
        char poppedData = temp->data;
        top = top->next;
        delete temp;
        return poppedData;
    }

    char peek() {
        return isEmpty() ? '\0' : top->data;
    }
};
