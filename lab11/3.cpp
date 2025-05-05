#include <iostream>
#include <list>
using namespace std;

const int TABLE_SIZE = 10;

class HashTable {
private:
    list<int> table[TABLE_SIZE];  // Array of linked lists

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    void insert(int key) {
        int index = hashFunction(key);

        for (int val : table[index]) {
            if (val == key) {
                cout << "Key already exists in the chain at index " << index << endl;
                return;
            }
        }

        table[index].push_back(key);
        cout << "Inserted " << key << " at index " << index << endl;
    }

    void remove(int key) {
        int index = hashFunction(key);
        auto& chain = table[index];

        for (auto it = chain.begin(); it != chain.end(); ++it) {
            if (*it == key) {
                chain.erase(it);
                cout << "Key " << key << " deleted from index " << index << endl;
                return;
            }
        }

        cout << "Key " << key << " not found in chain at index " << index << endl;
    }

    void search(int key) {
        int index = hashFunction(key);
        for (int val : table[index]) {
            if (val == key) {
                cout << "Key " << key << " found at index " << index << endl;
                return;
            }
        }
        cout << "Key " << key << " not found in chain at index " << index << endl;
    }

    void display() {
        cout << "Hash Table contents (Separate Chaining):" << endl;
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << " --> ";
            for (int val : table[i]) {
                cout << val << " -> ";
            }
            cout << "NULL" << endl;
        }
    }
};

int main() {
    HashTable ht;
    int choice, key;

    do {
        cout << "\n--- Hash Table Menu (Separate Chaining) ---\n";
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
