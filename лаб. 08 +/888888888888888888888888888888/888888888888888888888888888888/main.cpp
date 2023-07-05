#include <iostream>
#include "Queue.h"

using namespace std;

int main() {
    int maxSize;
    char sentinel;
    cout << "Enter maximum queue size: ";
    cin >> maxSize;
    cout << "Enter sentinel character: ";
    cin >> sentinel;

    Queue q(maxSize, sentinel);

    int choice;
    char element;
    while (true) {
        cout << endl;
        cout << "Menu:" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Get queue size" << endl;
        cout << "4. Print queue" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter element: ";
            cin >> element;
            q.enqueue(element);
            break;
        case 2:
            if (!q.getSize()) {
                cout << "Error: queue is empty." << endl;
                break;
            }
            cout << "Dequeued element: " << q.dequeue() << endl;
            break;
        case 3:
            cout << "Current queue size: " << q.getSize() << endl;
            break;
        case 4:
            cout << "Queue contents: ";
            q.printQueue();
            break;
        case 5:
            return 0;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}
