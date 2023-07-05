#include <iostream>
#include <vector>
#include <string>
#include <chrono>

// ���������, �������������� ����� �� ��������
struct ParkingSpot {
    int spotNumber;
    std::string owner;
};

// ����� ���-�������
class HashTable {
private:
    static const int TABLE_SIZE = 10; // ������ �������
    std::vector<ParkingSpot*> table[TABLE_SIZE];

    // ���-������� �� ������ ������������ ��� ��� ������
    int calculateHash(const std::string& key) {
        int hash = 0;
        for (char c : key) {
            hash ^= c;
        }
        return hash % TABLE_SIZE;
    }

public:
    // ���������� �������� � ���-�������
    void insertSpot(int spotNumber, const std::string& owner) {
        int index = calculateHash(std::to_string(spotNumber));
        ParkingSpot* newSpot = new ParkingSpot{ spotNumber, owner };
        table[index].push_back(newSpot);
    }

    // ����� �������� � ���-�������
    ParkingSpot* findSpot(int spotNumber) {
        int index = calculateHash(std::to_string(spotNumber));
        for (ParkingSpot* spot : table[index]) {
            if (spot->spotNumber == spotNumber) {
                return spot;
            }
        }
        return nullptr;
    }

    // �������� �������� �� ���-�������
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

    // ����� ���� ������� ���-�������
    void printTable() {
        std::cout << "���-�������:\n";
        for (int i = 0; i < TABLE_SIZE; ++i) {
            std::cout << "������ " << i << ": ";
            for (const auto& spot : table[i]) {
                std::cout << "�" << spot->spotNumber << " - " << spot->owner << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "Rus");
    HashTable parking; // �������� ������� ���-������� ��� ��������

    int option;
    do {
        std::cout << "�������� ��������:\n";
        std::cout << "1. �������� ����� �� ��������\n";
        std::cout << "2. ����� ��������� �����\n";
        std::cout << "3. ������� �����\n";
        std::cout << "4. ������� ��� �������\n";
        std::cout << "0. �����\n";
        std::cin >> option;

        if (option == 1) {
            int spotNumber;
            std::string owner;
            std::cout << "������� ����� �����: ";
            std::cin >> spotNumber;
            std::cout << "������� ��������� �����: ";
            std::cin >> owner;
            parking.insertSpot(spotNumber, owner);
        }
        else if (option == 2) {
            int spotNumber;
            std::cout << "������� ����� ����� ��� ������: ";
            std::cin >> spotNumber;

            auto start = std::chrono::high_resolution_clock::now();
            ParkingSpot* foundSpot = parking.findSpot(spotNumber);
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

            if (foundSpot != nullptr) {
                std::cout << "����� " << spotNumber << " ����������� " << foundSpot->owner << std::endl;
            }
            else {
                std::cout << "����� " << spotNumber << " �� �������." << std::endl;
            }

            std::cout << "����� ������: " << duration.count() << " �����������\n";
        }
        else if (option == 3) {
            int spotNumber;
            std::cout << "������� ����� ����� ��� ��������: ";
            std::cin >> spotNumber;
            parking.removeSpot(spotNumber);
        }
        else if (option == 4) {
            parking.printTable();
        }
    } while (option != 0);

    return 0;
}
