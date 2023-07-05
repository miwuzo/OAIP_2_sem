#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] >= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    srand(time(0));

    int size_a, size_b;
    cout << "������� ������ ������� A: ";
    cin >> size_a;
    cout << "������� ������ ������� B: ";
    cin >> size_b;

    vector<int> A(size_a);
    vector<int> B(size_b);

    // ���������� �������� A � B ���������� ������� �� 0 �� 100
    for (int i = 0; i < size_a; i++) {
        A[i] = rand() % 101;
    }

    for (int i = 0; i < size_b; i++) {
        B[i] = rand() % 101;
    }

    // ����� �������� A � B
    cout << "������ A: ";
    for (int i = 0; i < A.size(); i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    cout << "������ B: ";
    for (int i = 0; i < B.size(); i++) {
        cout << B[i] << " ";
    }
    cout << endl;

    // ����� ������������� �������� � ������� B
    int max_b = *max_element(B.begin(), B.end());

    vector<int> C;

    // ������� ��������� �� ������� A � ������ C, ������� ������ ������������� �������� B
    for (int i = 0; i < size_a; i++) {
        if (A[i] < max_b) {
            C.push_back(A[i]);
        }
    }

    // ���������� ������� C �� �������� � ������� ���������� ���������
    clock_t startTime = clock();
    bubbleSort(C);
    clock_t endTime = clock();

    double bubbleSortTime = double(endTime - startTime) / CLOCKS_PER_SEC;

    // ����� ���������������� ������� C
    cout << "������ C (���������� ���������): ";
    for (int i = 0; i < C.size(); i++) {
        cout << C[i] << " ";
    }
    cout << endl;

    // ���������� ������� C �� �������� � ������� ������� ����������
    startTime = clock();
    quickSort(C, 0, C.size() - 1);
    endTime = clock();

    double quickSortTime = double(endTime - startTime) / CLOCKS_PER_SEC;

    // ����� ���������������� ������� C
    cout << "������ C (������� ����������): ";
    for (int i = 0; i < C.size(); i++) {
        cout << C[i] << " ";
    }
    cout << endl;

    // ����� ������� ���������� ����������
    cout << "����� ���������� ���������� ���������: " << bubbleSortTime << " ������" << endl;
    cout << "����� ���������� ������� ����������: " << quickSortTime << " ������" << endl;

    return 0;
}
