#include <iostream>
#include <fstream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    void addNode(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
        cout << "Element added successfully!" << endl;
    }

    void deleteNode(int data) {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        if (head->data == data) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Element deleted successfully!" << endl;
            return;
        }

        Node* current = head;
        while (current->next != NULL && current->next->data != data) {
            current = current->next;
        }

        if (current->next == NULL) {
            cout << "Element not found!" << endl;
            return;
        }

        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
        cout << "Element deleted successfully!" << endl;
    }

    void searchNode(int data) {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* current = head;
        while (current != NULL && current->data != data) {
            current = current->next;
        }

        if (current == NULL) {
            cout << "Element not found!" << endl;
        }
        else {
            cout << "Element found!" << endl;
        }
    }

    void displayList() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void saveToFile(string filename) {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        ofstream file(filename);

        if (file.is_open()) {
            Node* current = head;
            while (current != NULL) {
                file << current->data << " ";
                current = current->next;
            }
            file.close();
            cout << "List saved to file!" << endl;
        }
        else {
            cout << "Unable to open file!" << endl;
        }
    }

    void loadFromFile(string filename) {
        ifstream file(filename);

        if (file.is_open()) {
            int data;
            while (file >> data) {
                addNode(data);
            }
            file.close();
            cout << "List loaded from file!" << endl;
        }
        else {
            cout << "Unable to open file!" << endl;
        }
    }

    void sumOfElements() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        int sum = 0;
        Node* current = head;
        while (current != NULL) {
            int lastDigit = current->data % 10;
            if (current->data > 0 && lastDigit == 7) {
                sum += current->data;
            }
            current = current->next;
        }

        if (sum == 0) {
            cout << "No elements found with last digit 7!" << endl;
        }
        else {
            cout << "Sum of positive elements with last digit 7: " << sum << endl;
        }
    }
};

int main() {
    LinkedList list;
    int choice, data;
    string filename;

    do {
        cout << endl;
        cout << "1. Add element (only int)" << endl;
        cout << "2. Delete element" << endl;
        cout << "3. Search element" << endl;
        cout << "4. Display list" << endl;
        cout << "5. Save list to file" << endl;
        cout << "6. Load list from file" << endl;
        cout << "7. Sum of + elements with last digit 7" << endl;
        cout << "8. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter element to add: ";
            cin >> data;
            list.addNode(data);
            break;
        case 2:
            cout << "Enter element to delete: ";
            cin >> data;
            list.deleteNode(data);
            break;
        case 3:
            cout << "Enter element to search: ";
            cin >> data;
            list.searchNode(data);
            break;
        case 4:
            list.displayList();
            break;
        case 5:
            cout << "Enter file name: ";
            cin >> filename;
            list.saveToFile(filename);
            break;
        case 6:
            cout << "Enter file name: ";
            cin >> filename;
            list.loadFromFile(filename);
            break;
        case 7:
            list.sumOfElements();
            break;
        case 8:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 8);

    return 0;
}