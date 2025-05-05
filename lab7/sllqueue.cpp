#include <iostream>
using namespace std;

class sllqueue {
private:
    struct node {
        int data;
        node* next;
        node(int value) {
            data = value;
            next = nullptr;
        }
    } *head, *tail;

public:
    sllqueue();
    void enqueue(int value);
    void dequeue();
    void peek();
};

int main() {
    int ch = 0, value;
    cout << "************ MENU ************\n\n";
    cout << "1 -> enqueue\n";

    cout << "2 -> dequeue\n";
    cout << "3 -> peek\n";
    cout << "4 -> exit\n\n";
    
    sllqueue queue;
    
    while (ch != 4) {
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "Enter a value to enqueue: ";
                cin >> value;
                queue.enqueue(value);
                break;
            case 2:
                queue.dequeue();
                break;
            case 3:
                queue.peek();
                break;
            case 4:
                cout << "\n\n\nSuccessfully completed\n\n\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
                break;
        }
    }
}

sllqueue::sllqueue() {
    head = nullptr;
    tail = nullptr;
}

void sllqueue::enqueue(int value) {
    node* newnode = new node(value);
    
    if (head == nullptr) {
        head = tail = newnode;
    } else {
        tail->next = newnode;
        tail = newnode;
    }
    
    cout << "\n\nEnqueued successfully\n\n";
}

void sllqueue::dequeue() {
    if (head == nullptr) {
        cout << "\n\nUnderflow! The queue is empty.\n\n";
        return;
    }
    
    node* tempNode = head;
    head = head->next;
    
    if (head == nullptr) {
        tail = nullptr;
    }
    
    cout << "\n\nDequeued value is: " << tempNode->data << "\n\n";
    delete tempNode;
}

void sllqueue::peek() {
    if (head == nullptr) {
        cout << "\n\nUnderflow! The queue is empty.\n\n";
        return;
    }
    
    cout << "\n\nThe peek value is: " << head->data << "\n\n";
}
