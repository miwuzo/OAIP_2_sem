// main.cpp
#include <iostream>
#include "queue.h"
#include "menu.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int size;
    cout << "������� ������ �������: ";
    cin >> size;
    Queue q(size);

    char target;
    cout << "������� ��������� ������: ";
    cin >> target;

    char c;
    do {
        cout << "������� ������: ";
        cin >> c;
        q.enqueue(c);
    } while (c != target);

    q.dequeue();
    q.dequeue();
    cout << "������ �������: " << q.size() << endl;

    int choice;
    do {
        printMenu();
        cout << "�������� ��������: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "������� ������: ";
            cin >> c;
            q.enqueue(c);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            cout << "������ � ������ �������: " << q.peek() << endl;
            break;
        case 4:
            cout << "������ �������: " << q.size() << endl;
            break;
        case 5:
            cout << "�����" << endl;
            break;
        default:
            cout << "������������ �����. ���������� ��� ���." << endl;
            break;
        }

    } while (choice != 5);

    return 0;
}
