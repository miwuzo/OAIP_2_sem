#include <iostream>
#include <string>

using namespace std;

int main()
{
    setlocale(0, "rus");
    FILE* F1; FILE* F2; errno_t err, err2;
    err = fopen_s(&F1, "F1.txt", "w");
    if (err != NULL) {
        perror("Невозможно oткрыть файл\n");
        return -1;
    }
    err2 = fopen_s(&F2, "F2.txt", "w");
    if (err != NULL) {
        perror("Невозможно oткрыть файл\n");
        return -1;
    }
    char mass[50], str[10]; int a;
    cout << "Number: " << endl;
    cin >> a;
    gets_s(str);
    for (int i = 0; i < 5; i++)
    {
        printf("String  %d : \n", i + 1);
        gets_s(mass);
        fputs(mass, F1);
        fputs("\n", F1);
        if (strlen(mass) > a) {
            fputs(mass, F2);
            fputs("\n", F2);
        }

    }
    if (fclose(F1) == EOF)
        printf("Ошибка закрытия f-файла\n");
    if (fclose(F2) == EOF)
        printf("Ошибка закрытия g-файла\n");
    system("pause");
    return 0;
}