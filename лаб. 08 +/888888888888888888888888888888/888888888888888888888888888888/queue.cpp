#include "Queue.h"

Queue::Queue(int maxSize, char sentinel) {
    this->maxSize = maxSize;
    this->sentinel = sentinel;
}

void Queue::enqueue(char element) {
    if (q.size() >= maxSize) {
        cout << "Error: queue is full." << endl;
        return;
    }
    q.push(element);
    if (element == sentinel) {
        q.pop();
        q.pop();
    }
}

char Queue::dequeue() {
    char element = q.front();
    q.pop();
    return element;
}

int Queue::getSize() {
    return q.size();
}

void Queue::printQueue() {
    queue<char> temp = q; // создаем копию очереди
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;
}
