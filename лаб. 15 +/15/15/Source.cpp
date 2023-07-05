#include <iostream>
#include <vector>
#include <string>
#include <chrono>

// Структура, представляющая место на парковке
struct ParkingSpot {
    int spotNumber;
    std::string owner;
};

// Класс хеш-таблицы
class HashTable {
private:
    static const int TABLE_SIZE = 10; // Размер таблицы
    std::vector<ParkingSpot*> table[TABLE_SIZE];

    // Хеш-функция на основе исключающего ИЛИ для строки
    int calculateHash(const std::string& key) {
        int hash = 0;
        for (char c : key) {
            hash ^= c;
        }
        return hash % TABLE_SIZE;
    }

public:
    // Добавление элемента в хеш-таблицу
    void insertSpot(int spotNumber, const std::string& owner) {
        int index = calculateHash(std::to_string(spotNumber));
        ParkingSpot* newSpot = new ParkingSpot{ spotNumber, owner };
        table[index].push_back(newSpot);
    }

    // Поиск элемента в хеш-таблице
    ParkingSpot* findSpot(int spotNumber) {
        int index = calculateHash(std::to_string(spotNumber));
        for (ParkingSpot* spot : table[index]) {
            if (spot->spotNumber == spotNumber) {
                return spot;
            }
        }
        return nullptr;
    }

    // Удаление элемента из хеш-таблицы
    void removeSpot(int spotNumber) {
        int index = calculateHash(std::to_string(spotNumber));
        std::vector<ParkingSpot*>& spotList = table[index];
        for (auto it = spotList.begin(); it != spotList.end(); ++it) {
            if ((*it)->spotNumber == spotNumber) {
                delete* it;
                spotList.erase(it);
                return;
            }
        }
    }

    // Вывод всей таблицы хеш-таблицы
    void printTable() {
        std::cout << "Хеш-таблица:\n";
        for (int i = 0; i < TABLE_SIZE; ++i) {
            std::cout << "Индекс " << i << ": ";
            for (const auto& spot : table[i]) {
                std::cout << "№" << spot->spotNumber << " - " << spot->owner << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "Rus");
    HashTable parking; // Создание объекта хеш-таблицы для парковки

    int option;
    do {
        std::cout << "Выберите действие:\n";
        std::cout << "1. Добавить место на парковке\n";
        std::cout << "2. Найти владельца места\n";
        std::cout << "3. Удалить место\n";
        std::cout << "4. Вывести всю таблицу\n";
        std::cout << "0. Выход\n";
        std::cin >> option;

        if (option == 1) {
            int spotNumber;
            std::string owner;
            std::cout << "Введите номер места: ";
            std::cin >> spotNumber;
            std::cout << "Введите владельца места: ";
            std::cin >> owner;
            parking.insertSpot(spotNumber, owner);
        }
        else if (option == 2) {
            int spotNumber;
            std::cout << "Введите номер места для поиска: ";
            std::cin >> spotNumber;

            auto start = std::chrono::high_resolution_clock::now();
            ParkingSpot* foundSpot = parking.findSpot(spotNumber);
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

            if (foundSpot != nullptr) {
                std::cout << "Место " << spotNumber << " принадлежит " << foundSpot->owner << std::endl;
            }
            else {
                std::cout << "Место " << spotNumber << " не найдено." << std::endl;
            }

            std::cout << "Время поиска: " << duration.count() << " микросекунд\n";
        }
        else if (option == 3) {
            int spotNumber;
            std::cout << "Введите номер места для удаления: ";
            std::cin >> spotNumber;
            parking.removeSpot(spotNumber);
        }
        else if (option == 4) {
            parking.printTable();
        }
    } while (option != 0);

    return 0;
}
