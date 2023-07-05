#include <iostream>
using namespace std;

float findX(float (*f)(float), float a, float b, float e) {

	float x;

	do
	{
		x = (a + b) / 2;

		if (f(x) * f(a) <= 0)
		{
			b = x;
		}
		else {
			a = x;
		}

	} while (abs(a - b) > 2 * e);

	return x;
}






float f1(float x) {
	return (pow(x, 3) + x - 4);
}

float f2(float x) {
	return (1 - pow(x, 2));
}


float all_funk() {
	float a, b, e;
	cout << "write a" << endl;
	cin >> a;
	cout << "write b" << endl;
	cin >> b;
	cout << "write e" << endl;
	cin >> e;

	cout << "zadanye 1" << endl;
	cout << "x1=" << findX(f1, a, b, e) << endl;
	cout << "x2=" << findX(f2, a, b, e) << endl << "\n";
	return 0;
}








void strsum(int, ...);

void strsum(int n, ...)
{
	char* size = new char[n];
	cout << "write a text" << endl;
	cin.getline(size, n, '.');
	int i = 0, probel = 0, posledn = 0, length = strlen(size), max = 0, slovo;
	while (i != length)
	{
		if (*(size + i) == ' ')
		{
			probel = i;
			int clovo = probel - posledn - 1;
			if (clovo > max)
			{ max = clovo;}
			posledn = probel;
		}
		
		
		if ((i + 1) == length)
		{
			int clovo = length - posledn - 1;
			if (clovo > max)
			{
				max = clovo;
			}
		}
		i++;
	}
	cout << "answer: " << max;
}







int main() {
	all_funk();
	setlocale(LC_CTYPE, "Russian");
	strsum(100); cout << endl;
	
}