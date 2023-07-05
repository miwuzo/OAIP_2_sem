#pragma once
// queue.h
#ifndef QUEUE_H
#define QUEUE_H

class Queue {
private:
    char* arr;
    int front;
    int rear;
    int capacity;
    int count;
public:
    Queue(int size);
    ~Queue();
    void enqueue(char item);
    char dequeue();
    char peek();
    int size();
};

#endif
