#pragma once

#include <queue>
#include <iostream>
using namespace std;

class Queue {
public:
    Queue(int maxSize, char sentinel); // ����������� ������
    void enqueue(char element); // ���������� �������� � �������
    char dequeue(); // �������� �������� �� �������
    int getSize(); // ��������� ������� �������
    void printQueue(); // ����� ���� ��������� �������
private:
    queue<char> q; // ����������� ������� ��� �������� ���������
    int maxSize; // ������������ ������ �������
    char sentinel; // ��������� ������
};
