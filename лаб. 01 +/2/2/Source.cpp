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
	return (pow(x, 3) + x - 3);
}

float f2(float x) {
	return (pow(cos(x), 3));
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

double sum(int n, ...);

double sum(int n, ...) {
	int res = 0;
	int* p = &n + 1;
	for (; n > 0; n--)
		res += *(p++) * (*(p + 1));
	return res;
}


int main() {
	cout << "zadanye 2" << "\n" << "sum =" << sum(4, 4, 3, 5, 6, 4) << endl;
	all_funk();
}