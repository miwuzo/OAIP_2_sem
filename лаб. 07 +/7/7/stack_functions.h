#pragma once

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <list>

using namespace std;

class Stack {
private:
    list<int> data;

public:
    void push(int element) {
        data.push_back(element);
    }

    int pop() {
        if (data.empty()) {
            throw runtime_error("Stack is empty");
        }
        int element = data.back();
        data.pop_back();
        return element;
    }

    bool empty() const {
        return data.empty();
    }

    void clear() {
        data.clear();
    }

    void save(const string& filename) const {
        ofstream file(filename);
        if (!file.is_open()) {
            throw runtime_error("Cannot open file");
        }
        for (int element : data) {
            file << element << " ";
        }
        file.close();
    }

    void load(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            throw runtime_error("Cannot open file");
        }
        int element;
        while (file >> element) {
            data.push_back(element);
        }
        file.close();
    }

    void remove_first_duplicate() {
        if (data.size() <= 1) {
            return;
        }
        for (auto it1 = data.end(); it1 != data.begin(); --it1) {
            auto it2 = find(next(it1), data.end(), *it1);
            if (it2 != data.end()) {
                data.erase(it2);
                return;
            }
        }
    }
};
