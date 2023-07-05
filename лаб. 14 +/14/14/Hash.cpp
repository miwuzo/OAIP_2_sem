#include "Hash.h"
#include <iostream>
#include <chrono>
using namespace std;

struct AAA
{
    int key;
    char* mas;
    AAA(int k, char* z)
    {
        key = k;  mas = z;
    }
    AAA() {}
};

//-------------------------------
int key(void* d)
{
    AAA* f = (AAA*)d;
    return f->key;
}

//-------------------------------
void AAA_print(void* d)
{
    printf(" ключ %d - %s\n", ((AAA*)d)->key, ((AAA*)d)->mas);
}

//-------------------------------
int main()
{
    setlocale(LC_ALL, "rus");
    AAA a1(1, (char*)"one"), a2(2, (char*)"two"), a3(4, (char*)"three"), a4(2, (char*)"fo");
    int siz = 10, choice, k;
    cout << "¬ведите размер хеш-таблицы" << endl;
    cin >> siz;

    Object H = create(siz, key);

    for (;;)
    {
        cout << "1 - вывод хеш-таблицы" << endl;
        cout << "2 - добавление элемента" << endl;
        cout << "3 - удаление элемента" << endl;
        cout << "4 - поиск элемента" << endl;
        cout << "0 - выход" << endl;
        cout << "сделайте выбор" << endl;
        cin >> choice;

        switch (choice)
        {
        case 0:
            exit(0);
        case 1:
            H.scan(AAA_print);
            break;
        case 2:
        {
            AAA* a = new AAA;
            char* str = new char[20];
            cout << "введите ключ" << endl;
            cin >> k;
            a->key = k;
            cout << "введите строку" << endl;
            cin >> str;
            a->mas = str;
            void* found = H.search(k);
            if (found != NULL)
            {
                cout << "Ёлемент с таким ключом уже существует" << endl;
                delete a;
                delete[] str;
            }
            else
            {
                if (H.N == H.size)
                    cout << "“аблица заполнена" << endl;
                else
                    H.insert(a);
            }
        }
        break;
        case 3:
        {
            cout << "введите ключ дл€ удалени€" << endl;
            cin >> k;
            void* found = H.search(k);
            if (found == NULL)
            {
                cout << "Ёлемент не найден" << endl;
            }
            else
            {
                H.deleteByValue(found);
                cout << "Ёлемент удален" << endl;
            }
        }
        break;
        case 4:
        {
            cout << "введите ключ дл€ поиска" << endl;
            cin >> k;
            auto start = chrono::high_resolution_clock::now();
            void* found = H.search(k);
            auto end = chrono::high_resolution_clock::now();
            if (found == NULL)
            {
                cout << "Ёлемент не найден" << endl;
            }
            else
            {
                AAA_print(found);
            }
            cout << "¬рем€ поиска: " << (chrono::duration_cast<chrono::nanoseconds>(end - start).count()) * 0.000000001 << " мс" << endl;
        }
        break;
        }
    }

    return 0;
}
