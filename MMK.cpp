#include <iostream>
#include <algorithm>
using namespace std;
#define min 1
#define max 1024
int main() {
	// log_2 x (1, 1024)
	int iter;
	double prev_x= min, x = 0, prev_y = log2(min), y = 0, S = 0, my_S;
	cin >> iter;
	double t = (max - min) / iter;
	for (int i = 1; i < iter; ++i) {
		x = i*t;
		y = log2(x);
		S += abs((prev_y + y)*(x - prev_x) / 2);
		prev_x = x;
		prev_y = y;
	}
	my_S = max * (log10(max) - 1) / log10(2) - min * (log10(min) - 1) / log10(2);
	cout << my_S - S;
	system("pause");
	return 0;
}