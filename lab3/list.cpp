#include <iostream>
using namespace std;

class List {
private:
    int arr[5];
    int size;

public:
    List() : size(0) {}

    void insertAtBeginning(int value);
    void insertAtEnd(int value);
    void insertAtPosition(int value, int pos);
    void deleteAtBeginning();
    void deleteAtEnd();
    void deleteAtPosition(int pos);
    int search(int value);
    void display();
    void rotate();
};

void List::insertAtBeginning(int value) {
    if (size == 5) {
        cout << "List is full" << endl;
        return;
    }
    for (int i = size; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = value;
    size++;
}

void List::insertAtEnd(int value) {
    if (size == 5) {
        cout << "List is full" << endl;
        return;
    }
    arr[size++] = value;
}

void List::insertAtPosition(int value, int pos) {
    if (size == 5 || pos < 0 || pos > size) {
        cout << "Invalid position or list is full" << endl;
        return;
    }
    for (int i = size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    size++;
}

void List::deleteAtBeginning() {
    if (size == 0) {
        cout << "List is empty" << endl;
        return;
    }
    for (int i = 0; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}

void List::deleteAtEnd() {
    if (size == 0) {
        cout << "List is empty" << endl;
        return;
    }
    size--;
}

void List::deleteAtPosition(int pos) {
    if (size == 0 || pos < 0 || pos >= size) {
        cout << "Invalid position or list is empty" << endl;
        return;
    }
    for (int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}

int List::search(int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

void List::display() {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void List::rotate() {
    if (size == 0) {
        cout << "List is empty" << endl;
        return;
    }
    int temp = arr[0];
    for (int i = 0; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arr[size - 1] = temp;
}

int main() {
    List list;
    int choice, value, pos;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete at Beginning\n";
        cout << "5. Delete at End\n";
        cout << "6. Delete at Position\n";
        cout << "7. Search\n";
        cout << "8. Display\n";
        cout << "9. Rotate\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                list.insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value to insert: ";
                cin >> value;
                list.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position: ";
                cin >> pos;
                list.insertAtPosition(value, pos);
                break;
            case 4:
                list.deleteAtBeginning();
                break;
            case 5:
                list.deleteAtEnd();
                break;
            case 6:
                cout << "Enter position: ";
                cin >> pos;
                list.deleteAtPosition(pos);
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> value;
                pos = list.search(value);
                if (pos != -1) {
                    cout << "Value found at position: " << pos << endl;
                } else {
                    cout << "Value not found" << endl;
                }
                break;
            case 8:
                list.display();
                break;
            case 9:
                list.rotate();
                break;
            case 10:
                return 0;
            default:
                cout << "Invalid choice" << endl;
        }
    }
}
