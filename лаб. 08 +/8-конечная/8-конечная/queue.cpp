// queue.cpp
#include <iostream>
#include "queue.h"

using namespace std;

Queue::Queue(int size) {
    arr = new char[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}

Queue::~Queue() {
    delete[] arr;
}

void Queue::enqueue(char item) {
    if (rear == capacity - 1) {
        cout << "Очередь полна!" << endl;
        return;
    }
    rear++;
    arr[rear] = item;
    count++;
}

char Queue::dequeue() {
    if (count == 0) {
        cout << "Очередь пуста!" << endl;
        return '\0';
    }
    char item = arr[front];
    front++;
    count--;
    return item;
}

char Queue::peek() {
    if (count == 0) {
        cout << "Очередь пуста!" << endl;
        return '\0';
    }
    cout << "Queue contains: ";
    for (int i = 0; i <= capacity; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int Queue::size() {
    return count;
}

void Queue::display() {
    if (isEmpty()) {
        cout << "Очередь пуста" << endl;
        return;
    }

    for (int i = front; i <= rear; i++) {
        cout << data[i] << " ";
    }
}
