#include <iostream>
#include <deque>
using namespace std;

string processString(string str) {
    deque<char> q;  // Queue ADT (deque used for back removal)

    for (char ch : str) {
        if (ch == '+') {
            if (!q.empty()) q.pop_back(); // Remove last inserted non-'+' element
        } else {
            q.push_back(ch); // Insert into queue
        }
    }

    // Build the final output string
    string result = "";
    while (!q.empty()) {
        result += q.front();
        q.pop_front();
    }
    return result;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    string output = processString(input);
    cout << "Output: " << output << endl;

    return 0;
}
