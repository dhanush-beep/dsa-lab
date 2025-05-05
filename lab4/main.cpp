//The main function

#include "list.h"
#include <iostream>
using namespace std;

int main() {
    ListADT list1, list2, list3;
    int choice, value;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert into List1\n";
        cout << "2. Insert into List2\n";
        cout << "3. Merge List1 & List2 into List3\n";
        cout << "4. Display Lists\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input! Enter a number.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Enter value for List1: ";
                cin >> value;
                list1.insertAscending(value);
                break;

            case 2:
                cout << "Enter value for List2: ";
                cin >> value;
                list2.insertAscending(value);
                break;

            case 3:
                list3 = ListADT::mergeLists(list1, list2);
                cout << "Lists merged successfully!\n";
                break;

            case 4:
                cout << "List1: ";
                list1.display();
                cout << "List2: ";
                list2.display();
                cout << "List3: ";
                list3.display();
                break;

            case 5:
                cout << "Exiting program...\n";
                return 0;

            default:
                cout << "Invalid choice! Enter a valid option (1-5).\n";
        }
    }

    return 0;
}
