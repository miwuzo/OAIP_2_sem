#include "stack.h"
#include <iostream>
#include <string>

using namespace std;

void print_menu() {
    cout << "Menu:\n"
        << "1. Push element to stack (int only)\n"
        << "2. Pop element from stack\n"
        << "3. Check if stack is empty\n"
        << "4. Clear stack\n"
        << "5. Save stack to file\n"
        << "6. Load stack from file\n"
        << "7. Remove first duplicate element\n"
        << "8. Exit\n";
}

int main() {
    Stack<int> stack;
    while (true) {
        print_menu();
        cout << "Enter option: ";
        int option;
        cin >> option;
        if (option == 1) {
            cout << "Enter element: ";
            int element;
            cin >> element;
            stack.push(element);
            cout << "Element " << element << " pushed to stack\n";
        }
        else if (option == 2) {
            try {
                int element = stack.pop();
                cout << "Element " << element << " popped from stack\n";
            }
            catch (const std::runtime_error& e) {
                cout << e.what() << endl;
            }
        }
        else if (option == 3) {
            if (stack.empty()) {
                cout << "Stack is empty\n";
            }
            else {
                cout << "Stack is not empty\n";
            }
        }
        else if (option == 4) {
            stack.clear();
            cout << "Stack cleared\n";
        }
        else if (option == 5) {
            cout << "Enter filename: ";
            string filename;
            cin >> filename;
            try {
                stack.save(filename);
                cout << "Stack saved to file " << filename << endl;
            }
            catch (const std::runtime_error& e) {
                cout << e.what() << endl;
            }
        }
        else if (option == 6) {
            cout << "Enter filename: ";
            string filename;
            cin >> filename;
            try {
                stack.load(filename);
                cout << "Stack loaded from file " << filename << endl;
            }
            catch (const std::runtime_error& e) {
                cout << e.what() << endl;
            }
        }
        else if (option == 7) {
            stack.remove_first_duplicate();
            cout << "First duplicate element removed from stack\n";
        }
        else if (option == 8) {
            break;
        }
        else {
            cout << "Invalid option\n";
        }
    }
    return 0;
}