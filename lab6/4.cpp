#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(') {
                st.push(c);
            } else {
                if (st.empty()) return false;
                char top = st.top();
                if ((c == ')' && top == '(')) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};

int main() {
    Solution sol;
    int choice;
    string expression;
    
    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter expression: ";
                cin >> expression;
                if (sol.isValid(expression)) {
                    cout << "Balanced" << endl;
                } else {
                    cout << "Not Balanced" << endl;
                }
                break;
            case 2:
                cout << "Exiting program..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    
    return 0;
}
