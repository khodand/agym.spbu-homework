#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <cmath>
#include <time.h>
using namespace std;
#define min 1
#define max 1024
int main() { // S = Spr * K / N
	// log_2 x (1, 1024)
	int iter;
	double prev_x = min, x = 0, prev_y = log2(min), y = 0, S = 0, my_S;
	cout << "Iterations number(trapeze) = ";
	cin >> iter;
	double t = (max - min) / iter;
	for (int i = 1; i < iter; ++i) {
		x = i*t;
		y = log2(x);
		S += abs((prev_y + y)*(x - prev_x) / 2); // трапеции
		prev_x = x;
		prev_y = y;
	}
	my_S = max * (log10(max) - 1) / log10(2) - min * (log10(min) - 1) / log10(2); // интеграл 
	double mmk_S;
	srand(time(NULL));
	int points_number, K = 0, N = 0;
	cout << "Points number(mmk) = ";
	cin >> points_number;
	for (int i = 0; i < points_number; ++i) { // пр-уг = 11 * 1023
		x = 1 + rand() % 1023;
		int temp = log2(max);
		y = log2(min) + (rand() % temp);
		if (y <= log2(x))
			++K;
		++N;
	}
	mmk_S = 11 * 1023 * K / N;
	cout << "mmk_S = " << mmk_S << endl << "trapeze_S = " << S << endl << "integral_S = " << my_S << endl;
	system("pause");
	return 0;
}