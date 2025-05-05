#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;
const int EMPTY = -1;
const int DELETED = -2;

class HashTable {
private:
    int table[TABLE_SIZE];

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = EMPTY;
        }
    }

    void insert(int key) {
        int index = hashFunction(key);
        int i = 0;

        while (i < TABLE_SIZE) {
            int newIndex = (index + i * i) % TABLE_SIZE;

            if (table[newIndex] == EMPTY || table[newIndex] == DELETED) {
                table[newIndex] = key;
                cout << "Inserted " << key << " at index " << newIndex << endl;
                return;
            }

            if (table[newIndex] == key) {
                cout << "Key already exists at index " << newIndex << endl;
                return;
            }

            i++;
        }

        cout << "Hash Table is full! Cannot insert key." << endl;
    }

    void search(int key) {
        int index = hashFunction(key);
        int i = 0;

        while (i < TABLE_SIZE) {
            int newIndex = (index + i * i) % TABLE_SIZE;

            if (table[newIndex] == EMPTY) {
                break;
            }

            if (table[newIndex] == key) {
                cout << "Key " << key << " found at index " << newIndex << endl;
                return;
            }

            i++;
        }

        cout << "Key " << key << " not found." << endl;
    }

    void remove(int key) {
        int index = hashFunction(key);
        int i = 0;

        while (i < TABLE_SIZE) {
            int newIndex = (index + i * i) % TABLE_SIZE;

            if (table[newIndex] == EMPTY) {
                break;
            }

            if (table[newIndex] == key) {
                table[newIndex] = DELETED;
                cout << "Key " << key << " deleted from index " << newIndex << endl;
                return;
            }

            i++;
        }

        cout << "Key " << key << " not found. Cannot delete." << endl;
    }

    void display() {
        cout << "Hash Table contents:" << endl;
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << " --> ";
            if (table[i] == EMPTY) {
                cout << "EMPTY" << endl;
            } else if (table[i] == DELETED) {
                cout << "DELETED" << endl;
            } else {
                cout << table[i] << endl;
            }
        }
    }
};

int main() {
    HashTable ht;
    int choice, key;

    do {
        cout << "\n--- Hash Table Menu (Quadratic Probing) ---\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                ht.insert(key);
                break;
            case 2:
                cout << "Enter key to delete: ";
                cin >> key;
                ht.remove(key);
                break;
            case 3:
                cout << "Enter key to search: ";
                cin >> key;
                ht.search(key);
                break;
            case 4:
                ht.display();
                break;
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 5);

    return 0;
}
