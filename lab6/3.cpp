#include "stack.h"
#include <iostream>
#include <cctype>
#include <cmath>
#include <string>

using namespace std;

class Expression {
public:
    static int precedence(char op) {
        if (op == '=') return 0; // Lowest precedence
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/' || op == '%') return 2;
        return 0;
    }

    static void infixToPostfix(const string& infix, string& postfix) {
        Stack stack;
        postfix = "";

        for (char ch : infix) {
            if (isalnum(ch)) {  // Operand
                postfix += ch;
            } 
            else if (ch == '(') {  // Left parenthesis
                stack.push(ch);
            } 
            else if (ch == ')') {  // Right parenthesis
                while (!stack.isEmpty() && stack.peek() != '(') {
                    postfix += stack.pop();
                }
                stack.pop();  // Remove '('
            } 
            else {  // Operator
                while (!stack.isEmpty() && precedence(stack.peek()) >= precedence(ch)) {
                    postfix += stack.pop();
                }
                stack.push(ch);
            }
        }

        while (!stack.isEmpty()) {  // Pop remaining operators
            postfix += stack.pop();
        }
    }
};

class IntStack {
private:
    struct IntNode {
        int data;
        IntNode* next;
    };
    IntNode* top;
public:
    IntStack() { top = nullptr; }

    bool isEmpty() { return top == nullptr; }

    void push(int data) {
        IntNode* newNode = new IntNode();
        newNode->data = data;
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow\n";
            return 0;
        }
        IntNode* temp = top;
        int poppedData = temp->data;
        top = top->next;
        delete temp;
        return poppedData;
    }

    int peek() {
        return isEmpty() ? 0 : top->data;
    }
};

class PostfixEvaluator {
public:
    static int evaluatePostfix(const string& postfix) {
        IntStack stack;

        for (char ch : postfix) {
            if (isdigit(ch)) {
                stack.push(ch - '0');  // Convert char to int
            } 
            else {  // Operator
                int val2 = stack.pop();
                int val1 = stack.pop();
                switch (ch) {
                    case '+': stack.push(val1 + val2); break;
                    case '-': stack.push(val1 - val2); break;
                    case '*': stack.push(val1 * val2); break;
                    case '/': stack.push(val1 / val2); break;
                    case '%': stack.push(val1 % val2); break;
                }
            }
        }
        return stack.pop();
    }
};

int main() {
    string infix, postfix;
    int choice;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Get Infix Expression\n";
        cout << "2. Convert Infix to Postfix\n";
        cout << "3. Evaluate Postfix Expression\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter infix expression: ";
                cin >> infix;
                break;
            case 2:
                Expression::infixToPostfix(infix, postfix);
                cout << "Postfix Expression: " << postfix << endl;
                break;
            case 3:
                cout << "Evaluated Result: " << PostfixEvaluator::evaluatePostfix(postfix) << endl;
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
