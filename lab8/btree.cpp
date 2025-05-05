#include <iostream>
#include <queue>
using namespace std;

class Tree {
    struct node {
        char data;
        struct node* left;
        struct node* right;

        node(char val) {
            data = val;
            left = right = nullptr;
        }
    };

public:
    node* root; // Root node of the tree

    Tree() { root = nullptr; } // Constructor

    void insert(char key);
    void inorder(node* root);
    void preorder(node* root);
    void postorder(node* root);
    bool search(char key);
    void menu();
};

void Tree::insert(char key) {
    node* newNode = new node(key);
    if (!root) {
        root = newNode;
        return;
    }

    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        if (!temp->left) {
            temp->left = newNode;
            return;
        } else {
            q.push(temp->left);
        }

        if (!temp->right) {
            temp->right = newNode;
            return;
        } else {
            q.push(temp->right);
        }
    }
}

void Tree::inorder(node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void Tree::preorder(node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void Tree::postorder(node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

bool Tree::search(char key) {
    if (!root) return false;

    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        if (temp->data == key)
            return true;

        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }

    return false;
}

void Tree::menu() {
    int choice;
    char value;
    do {
        cout << "\n--- Binary Tree Menu ---\n";
        cout << "1. Insert a node\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Preorder Traversal\n";
        cout << "4. Postorder Traversal\n";
        cout << "5. Search for an element\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a character to insert: ";
                cin >> value;
                insert(value);
                break;

            case 2:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;

            case 3:
                cout << "Preorder Traversal: ";
                preorder(root);
                cout << endl;
                break;

            case 4:
                cout << "Postorder Traversal: ";
                postorder(root);
                cout << endl;
                break;

            case 5:
                cout << "Enter a character to search: ";
                cin >> value;
                if (search(value))
                    cout << value << " found in the tree.\n";
                else
                    cout << value << " not found in the tree.\n";
                break;

            case 6:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Please enter a valid option.\n";
        }
    } while (choice != 6);
}

int main() {
    Tree tree;
    tree.menu(); // Start menu-driven program
    return 0;
}
