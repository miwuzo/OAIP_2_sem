#include <fstream>
#include <iostream>
#include <stdio.h>

void fromFile(char s[]); 
using namespace std;

void main()
{
    setlocale(LC_ALL, "rus");
    char buff[1000];  char str[1000];
    string s[1000];
    int i, j, t;


    cout << "Введите строку : ";
    gets_s(str);

    fromFile(str);

    cout << endl;

    t = 0;
    j = 0;
    ifstream fin("f1.txt");    
    if (!fin.is_open())
        cout << "Файл не может быть открыт!\n";
    else
    {
        while (!fin.eof())
        {
            fin >> buff;           
            j = j + 1;
            for (i = 0; i < strlen(buff); i++)
            {
                if (buff[i] == 'x')
                {
                    cout << buff << endl;
                    break;
                }
                else t = t + 1;
            }
        }
        if (t == j) cout << " Слов с буквой x нет";
    }
    fin.close();

}

void fromFile(char s[50]) 
{
    ofstream f("f1.txt");

    if (f.fail())
    {
        cout << "\n Ошибка открытия файла";
        exit(1);
    }
    else
        f << s;
    f.close();
}