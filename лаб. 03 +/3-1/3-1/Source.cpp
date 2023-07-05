#include <iostream>  
#include <string.h>  
#include <fstream>
#include<Windows.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    ofstream fout;
    int row = 0, symb = 0, k, i, j, length, count;
    char str1[100] = "sun day fun sun day";
    char str2[100] = "belstu is the best best uni";
    char str3[100] = "red car and blue motorbike";

    char words1[100][100];
    char words2[100][100];
    char words3[100][100];

    char buff1[100] = "\0";
    char buff2[100] = "\0";
    char buff3[100] = "\0";

    fout.open("FILE1.txt");
    if (!fout.is_open())
    {
        cout << "Ошибка cоздания файла";
    }
    else
    {
        fout << str1 << endl << str2 << endl << str3 << endl;
    }
    fout.close();

    ifstream fin;
    fin.open("FILE1.txt");
    if (!fin.is_open())
    {
        cout << "Ошибка открытия файла";
    }
    else
    {
        fout << str1 << endl << str2 << endl << str3;

        //ДЛЯ СТРОКИ 1
        for (k = 0; str1[k] != '\0'; k++)
        {
            if (str1[k] != ' ' && str1[k] != '\0')
            {
                //записывает все символы до пробела или до конца строки в двумерный массив
                words1[row][symb++] = str1[k]; //row - номер строки, symb - кол-во символов в строкe
            }
            else
            {
                words1[row][symb] = '\0'; //переходим на новую строку
                row++;
                symb = 0; //символы новой строки начинаются с 0
            }
        }
        words1[row][symb] = '\0'; //добавляем нулевой символ к последней строке двумерного массива

        length = row + 1; //хранит число строк

        //чтобы сравнить 0 строку с 1..length-1 строками в двумерном массиве
        bool flag = true;
        for (i = 0; i < length && flag == true; i++)
        {
            count = 1;
            for (j = i + 1; j < length && flag == true; j++)
            {
                int ai1 = 0;
                int aj1 = 0;
                while (words1[i][ai1] != '\0') ai1++;
                while (words1[j][aj1] != '\0') aj1++;
                bool fl1 = true;
                int c1 = 0, cm1 = 0;
                while (fl1)
                {
                    if (ai1 < aj1)
                    {
                        cm1--;
                        break;
                    }
                    else if (ai1 > aj1)
                    {
                        cm1++;
                        break;
                    }
                    else
                    {
                        if (words1[i][c1] == words1[j][c1])
                        {
                            c1++;
                            if (words1[i][c1] == '\0' && words1[j][c1] == '\0') break;
                        }
                        else
                        {
                            cm1--;
                            break;
                        }
                    }
                }

                //i - строки, j - символы строки
                if (cm1 == 0)// strcmp(words[i], words[j]) == 0 если строки равны, зайдет в if только если слово повторяется хотя бы второй раз
                {
                    count++;
                    //устанавливает в words[j] 0 чтобы избежать печатания одинaковых слов несколько раз
                    // strcpy_s(words1[j], "0");//вместо тех слов, которые уже встречались, запишутся нули  

                    ZeroMemory(words1[j], 100);

                    for (int m = 0; str1[m] != '\0'; m++)
                    {
                        buff1[m] = str1[m];
                    }
                    flag = false;//если хотя бы 1 раз вместо повторяющегося слова запишется 0 в двумерный массив, то выйдет сразу из for-for-if
                }
            }
        }

        //ДЛЯ СТРОКИ 2
        row = 0;
        symb = 0;
        for (k = 0; str2[k] != '\0'; k++)
        {
            if (str2[k] != ' ' && str2[k] != '\0')
            {
         
                words2[row][symb++] = str2[k];
            }
            else
            {
                words2[row][symb] = '\0'; 
                row++;
                symb = 0; 
            }
        }
        words2[row][symb] = '\0';

        length = row + 1; 

       
        flag = true;
        for (i = 0; i < length && flag == true; i++)
        {
            count = 1;
            for (j = i + 1; j < length && flag == true; j++)
            {
                int ai2 = 0;
                int aj2 = 0;
                while (words2[i][ai2] != '\0') ai2++;
                while (words2[j][aj2] != '\0') aj2++;
                bool fl2 = true;
                int c2 = 0, cm2 = 0;
                while (fl2)
                {
                    if (ai2 < aj2)
                    {
                        cm2--;
                        break;
                    }
                    else if (ai2 > aj2)
                    {
                        cm2++;
                        break;
                    }
                    else
                    {
                        if (words2[i][c2] == words2[j][c2])
                        {
                            c2++;
                            if (words2[i][c2] == '\0' && words2[j][c2] == '\0') break;
                        }
                        else
                        {
                            cm2--;
                            break;
                        }
                    }
                }

                if (cm2 == 0)
                {
                    count++;
                

                    ZeroMemory(words2[j], 100);
                    for (int m = 0; str2[m] != '\0'; m++)
                    {
                        buff2[m] = str2[m];
                    }
                    flag = false;
                }
            }
        }

        //ДЛЯ СТРОКИ 3
      
        row = 0;
        symb = 0;
        for (k = 0; str3[k] != '\0'; k++)
        {
            if (str3[k] != ' ' && str3[k] != '\0')
            {
               
                words3[row][symb++] = str3[k];
            }
            else
            {
                words3[row][symb] = '\0'; 
                row++;
                symb = 0; 
            }
        }
        words3[row][symb] = '\0';

        length = row + 1; 
        flag = true;
        for (i = 0; i < length && flag == true; i++)
        {
            count = 1;
            for (j = i + 1; j < length && flag == true; j++)
            {
                int ai3 = 0;
                int aj3 = 0;
                while (words3[i][ai3] != '\0') ai3++;
                while (words3[j][aj3] != '\0') aj3++;
                bool fl3 = true;
                int c3 = 0, cm3 = 0;
                while (fl3)
                {
                    if (ai3 < aj3)
                    {
                        cm3--;
                        break;
                    }
                    else if (ai3 > aj3)
                    {
                        cm3++;
                        break;
                    }
                    else
                    {
                        if (words3[i][c3] == words3[j][c3])
                        {
                            c3++;
                            if (words3[i][c3] == '\0' && words3[j][c3] == '\0') break;
                        }
                        else
                        {
                            cm3--;
                            break;
                        }
                    }
                }
                if (cm3 == 0) 
                {
                    count++;
                    

                    ZeroMemory(words3[j], 100);

                    for (int m = 0; str3[m] != '\0'; m++)
                    {
                        buff3[m] = str3[m];
                    }
                    flag = false;
                }
            }
        }

        fin.close();

        ofstream fout1;
        fout1.open("FILE2.txt");
        if (!fout1.is_open())
        {
            cout << "Ошибка открытия файла";
        }
        else
        {
            fout1 << buff1 << endl;
            fout1 << buff2 << endl;
            fout1 << buff3 << endl;
        }

        fout1.close();

        //НОМЕР СЛОВА, В КОТОРОМ БОЛЬШЕ ВСЕГО ЦИФР

        char string[] = "hochy34 na more12345 ochen7 ";
        int kol = 0;
        int numofword = 0;
        int numofwordmax = 0;
        int max = kol;
        int buff[2];
        fout.open("FILE1.txt", ios::app);

        if (!fout.is_open())
        {
            cout << "Ошибка cоздания файла";
        }
        else
        {
            fout << string << endl;
        }
        fout.close();

        fin.open("FILE1.txt");
        for (int k = 0; string[k] != '\0'; k++)
        {
            if ((string[k] >= '0') && (string[k] <= '9'))
            {
                kol++;
            }
            if (string[k] == ' ' || string[k + 1] == '\0')
            {
                numofword++;
                if (kol >= max)
                {
                    max = kol;
                    numofwordmax = numofword;
                }
                kol = 0;
            }
        }

        buff[0] = numofwordmax;
        buff[1] = max;
        ofstream fout2;
        fout2.open("FILE2.txt", ios::app);

        if (!fout2.is_open())
        {
            cout << "Ошибка открытия файла";
        }
        else
        {
            fout2 << "Номер слова с большим количеcтвом цифр ";
            fout2 << buff[0] << '\n';
            fout2 << "Количество цифр в этом слове ";
            fout2 << buff[1] << '\n';
        }
        return 0;
    }
}