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
	return (pow(x, 3) + x - 2);
}

float f2(float x) {
	return (sin(x) + 0.3);
}

float all_funk() {
	float a, b, e;
	cout << "write a" << endl;
	cin >> a;
	cout << "write b" << endl;
	cin >> b;
	cout << "write e" << endl;
	cin >> e;
	cout << endl;

	cout << "zadanye 1" << endl;
	cout << "x1=" << findX(f1, a, b, e) << endl;
	cout << "x2=" << findX(f2, a, b, e) << endl << "\n";

	return 0;
}

int DecToBi(int a, ...)
{
	char tA[1000];
	int* pA = &a;
	for (int i = 0; i < (a + 1) * 2; i += 2)
	{
		_itoa_s(*(pA + i), tA, 2);
		cout << tA << endl;
	}
	return 0;
}


int main() {
	all_funk();
	cout << "zadanye 2" << "\n";
	DecToBi(3, 4, 245, 2);

}