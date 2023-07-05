
# include <iostream> 
#include <iostream>
#include <fstream>
#include <string>
# define str_len 30                               
# define size 30  
#define chislo 9
int choice;
using namespace std;
struct table 
{
	string name;
	char lastname[255];
	char data_pr[chislo];
};

struct table list_of_ex[size];
struct table bad;
int current_size = 0;


void chek()
{
	int dol;
	
	int mes = (list_of_ex[current_size].data_pr[2] - '0') * 10 + list_of_ex[current_size].data_pr[3] - '0';
	
	int den = (list_of_ex[current_size].data_pr[0] - '0') * 10 + list_of_ex[current_size].data_pr[1] - '0';
	
	int cel = 0;
	int god = (list_of_ex[current_size].data_pr[4] - '0') * 1000 + (list_of_ex[current_size].data_pr[5] - '0') * 100 + (list_of_ex[current_size].data_pr[6] - '0') * 10 + list_of_ex[current_size].data_pr[7] - '0';

	while (list_of_ex[current_size].data_pr[0] > '3' || list_of_ex[current_size].data_pr[0] < '0' || mes > 12 || mes < 1 || den < 1 || den > 31) {



		cout << "||           Вы некорректно ввели дату!               ||\n";


		cout << "||           Введите дату(в формате ДДММГГГГ):          ||\n";

		cout << ">";
		cin >> list_of_ex[current_size].data_pr;
		
		mes = (list_of_ex[current_size].data_pr[2] - '0') * 10 + list_of_ex[current_size].data_pr[3] - '0';
		
		den = (list_of_ex[current_size].data_pr[0] - '0') * 10 + list_of_ex[current_size].data_pr[1] - '0';
		god = (list_of_ex[current_size].data_pr[4] - '0') * 1000 + (list_of_ex[current_size].data_pr[5] - '0') * 100 + (list_of_ex[current_size].data_pr[6] - '0') * 10 + list_of_ex[current_size].data_pr[7] - '0';

	}
}
void enter_new() 
{
	ofstream file1("information.txt", ios::app);
	cout << "Ввод информации" << endl;

	if (current_size < size)
	{
		cout << "Строка номер ";
		cout << current_size + 1;
		cout << endl << "название экзамена " << endl;

		cin.get();
		getline(cin, list_of_ex[current_size].name);


		file1 << list_of_ex[current_size].name << "\n";
		cout << endl << "Фамилия  " << endl;
		cin >> list_of_ex[current_size].lastname;
		file1 << list_of_ex[current_size].lastname << "\n";
		cout << endl << "Дата (в формате ДДММГГГГ)" << endl;
		static char data_pr[chislo];
		cin >> list_of_ex[current_size].data_pr;
		
		for (int i = 0; i < 8; i++)
		{
			if (list_of_ex[current_size].data_pr[i] > '9' || list_of_ex[current_size].data_pr[i] < '0') {

				cout << "\n";
				cout << "||       Вы некорректнo ввели дату     || \t\n";

				cout << "||   Введите дату в формате ДДММГГГГ   || \t\n";

				cin >> list_of_ex[current_size].data_pr;
			}
		}
		chek();
		file1 << list_of_ex[current_size].data_pr << "\n";
		current_size++;
	}
	else
		cout << "Введено максимальное кол-во строк";
}
void ifile()
{
	string strInf;
	ifstream file1("information.txt");
	while (file1)
	{
		getline(file1, strInf);
		cout << strInf << '\n';
	}
}
void del() 
{
	int d;
	cout << "\nНомер строки, которую надо удалить " << endl;
	cin >> d;

	if (d = 1)
	{
		for (int de1 = (d); de1 < current_size; de1++)
		{
			list_of_ex[de1] = list_of_ex[de1 + 1];
			current_size = current_size - 1;
		}
	}

	if (d != 32 and d!= 1)
	{
		for (int de1 = (d - 1); de1 < current_size; de1++)
		{
			list_of_ex[de1] = list_of_ex[de1 + 1];
			current_size = current_size - 1;
		}
	}
	if (d == 32)
	{
		for (int i = 0; i < size; i++)
		{
			list_of_ex[i] = bad;
		}
	}
}
void outputOneStructure(table oneex) 
{
	cout << "название ";
	cout << oneex.name << endl;
	cout << "Фамилия ";
	cout << oneex.lastname << endl;
	cout << "Дата ";
	cout << oneex.data_pr << endl;
	cout << endl;
}
void out() 
{
	int sw, n;
	cout << "1-вывод 1 строки" << endl;
	cout << "2-вывод всех строк" << endl;
	cin >> sw;
	if (sw == 1)
	{
		cout << "Номер выводимой строки " << endl;   cin >> n;  cout << endl;
		outputOneStructure(list_of_ex[n - 1]);
	}
	if (sw == 2)
	{
		for (int i = 0; i < current_size; i++)
		{
			outputOneStructure(list_of_ex[i]);
		}
	}
}
void search() 

{
	char for_search[30];

	cout << "Введите фамилию для поиска" << endl;;
	cin >> for_search;
	cout << endl;;
	int amount = 0;

	printf("Результат:\n");
	for (int i = 0; i < size; i++)
	{

		if (strcmp(for_search, list_of_ex[i].lastname) == 0)
		{
			amount++;
			outputOneStructure(list_of_ex[i]);
		}

	}
	printf("Всего найдено:%d\n\n", amount);


}
void write()
{
	ofstream out {"information.txt", ios::trunc};
	for (int i = 0; i < current_size; i++)
	{
		out << list_of_ex[i].name << endl;
		out << list_of_ex[i].lastname << endl;
		out << list_of_ex[i].data_pr << endl;
	}
}

int main()
{
	setlocale(LC_CTYPE, "Russian");
	char lastname[255];
	cout << "Данных нет" << endl;
	do
	{
		cout << "Введите:" << endl;
		cout << "1-для удаления записи " << endl;
		cout << "2-для ввода новой записи " << endl;
		cout << "3-для поиска по фамилии " << endl;
		cout << "4-для вывода записи " << endl;
		cout << "5-для вывода из файла " << endl;
		cout << "6-для выхода " << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:  del();	write(); break;
		case 2:  enter_new();  break;

		case 3: {
			cout << "Введите фамилию\n";
			search();
			break;
		}
		case 4:  out();	break;
		case 5: ifile();	break;
		}
	} while (choice != 6);
}

