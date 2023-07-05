// main.cpp
#include <iostream>
#include "queue.h"
#include "menu.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int size;
    cout << "Введите размер очереди: ";
    cin >> size;
    Queue q(size);

    char target;
    cout << "Введите эталонный символ: ";
    cin >> target;

    char c;
    do {
        cout << "Введите символ: ";
        cin >> c;
        q.enqueue(c);
    } while (c != target);

    q.dequeue();
    q.dequeue();
    cout << "Размер очереди: " << q.size() << endl;

    int choice;
    do {
        printMenu();
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введите символ: ";
            cin >> c;
            q.enqueue(c);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            cout << "Символ в начале очереди: " << q.peek() << endl;
            break;
        case 4:
            cout << "Размер очереди: " << q.size() << endl;
            break;
        case 5:
            cout << "Выход" << endl;
            break;
        default:
            cout << "Неправильный выбор. Попробуйте еще раз." << endl;
            break;
        }

    } while (choice != 5);

    return 0;
}
