#include <fstream>
#include <stdio.h>
#include <iostream>
int main()
{
    using namespace std;
    setlocale(LC_ALL, "");
    int rows, cols;
    errno_t err;
    FILE* f;

    err = fopen_s(&f, "a.txt", "w");
    if (err != 0)
    {
        perror("невозможно создать файл\n");
        return EXIT_FAILURE;
    }
   
    printf("введите количество строк\n");

    cin >> rows;

    printf("введите количество столбцов\n");
    cin >> cols;

    fprintf(f, "%d ", rows);
    fprintf(f, "%d\n", cols);

   
    int** A;  
    srand((unsigned)time(NULL));
    A = new int* [rows];
    for (int numb = 0; numb < rows; numb++) {
        A[numb] = new int[cols];
        for (int numb2 = 0; numb2 < cols; numb2++) {
            A[numb][numb2] = rand() % 100;
            fprintf(f, "%d ", A[numb][numb2]);
        }
        fprintf(f, "\n");
    }
    fclose(f);

    printf("Введите k-утю строку\n");
    int k, k_start = 0, k_end = 0;
    cin >> k;

    ifstream input("a.txt"); 
    float ch;
    int Count = 0;
    while (input >> ch) 
        Count++;
    cout << "Чисел в файле : " << Count << endl;
    input.close();


    int* mass = new int[Count];
    ifstream file("a.txt"); 

    int cols2, rows2;

    file >> rows2;
    file >> cols2;


    cout << rows2 << " " << cols2 << endl;

 

    errno_t file_b;
    FILE* b;

    file_b = fopen_s(&b, "b.txt", "w");
    if (file_b != 0)
    {
        perror("Невозможно создать файл\n");
        return EXIT_FAILURE;
    }


    for (int i = 0; i < (Count - 2); i++) {
        k_start++;
        if (k_start > ((k - 1) * cols2) && k_end < cols2) {
            file >> mass[i];
            fprintf(b, "%d ", mass[i]);
            k_end++;
        }
        else {
            file >> mass[i];
        }
    }

    fclose(b);
    printf("Данные записаны в файл b.txt\n");
    return 0;
}
