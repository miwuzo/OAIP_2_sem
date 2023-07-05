#pragma once

#include <queue>
#include <iostream>
using namespace std;

class Queue {
public:
    Queue(int maxSize, char sentinel); // конструктор класса
    void enqueue(char element); // добавление элемента в очередь
    char dequeue(); // удаление элемента из очереди
    int getSize(); // получение размера очереди
    void printQueue(); // вывод всех элементов очереди
private:
    queue<char> q; // стандартная очередь для хранения элементов
    int maxSize; // максимальный размер очереди
    char sentinel; // эталонный символ
};
