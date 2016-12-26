#include <iostream>

using namespace std;

int main() {
	double a = 1, b;
	while (a > 0) {
		b = a;
		a /= 2;
	}
	while (b / 2 - a < 1024) {
		a *= 2;
		b *= 2;
	}
	cout << b / 2 - a;
	system("pause");
	return 0;
}