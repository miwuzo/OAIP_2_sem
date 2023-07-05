#pragma once
#include <iostream>
#include <fstream>

template<typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
        Node(T data, Node* next = nullptr) : data(data), next(next) {}
    };
    Node* top_node;
public:
    Stack() : top_node(nullptr) {}
    ~Stack() {
        while (!empty()) {
            pop();
        }
    }
    void push(T data) {
        top_node = new Node(data, top_node);
    }
    T pop() {
        if (empty()) {
            throw std::runtime_error("Stack is empty");
        }
        T data = top_node->data;
        Node* old_top = top_node;
        top_node = top_node->next;
        delete old_top;
        return data;
    }
    bool empty() const {
        return top_node == nullptr;
    }
    void clear() {
        while (!empty()) {
            pop();
        }
    }
    void save(const std::string& filename) const {
        std::ofstream file(filename);
        if (!file) {
            throw std::runtime_error("Failed to open file for writing");
        }
        Node* current = top_node;
        while (current != nullptr) {
            file << current->data << std::endl;
            current = current->next;
        }
    }
    void load(const std::string& filename) {
        std::ifstream file(filename);
        if (!file) {
            throw std::runtime_error("Failed to open file for reading");
        }
        clear();
        T data;
        while (file >> data) {
            push(data);
        }
    }
    void remove_first_duplicate() {
        if (empty()) {
            return;
        }
        Node* current = top_node;
        while (current != nullptr) {
            Node* runner = current->next;
            Node* prev_runner = current;
            while (runner != nullptr) {
                if (runner->data == current->data) {
                    prev_runner->next = runner->next;
                    delete runner;
                    return;
                }
                prev_runner = runner;
                runner = runner->next;
            }
            current = current->next;
        }
    }
};
