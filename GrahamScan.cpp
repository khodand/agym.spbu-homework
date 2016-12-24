#include <iostream>
#include <vector>
#include <set>

#define X first
#define Y second

using namespace std;

vector < pair <double, double> > arr;
// y = kx + b
class line {
	double k, b;
public:
	line(pair <double, double> p1, pair <double, double> p2) {
		this->b = (p2.X*p1.Y - p2.Y*p1.X) / (p2.X - p1.X);
		this->k = (p2.Y - this->b) / p2.X;
	}
	bool is_under(pair <double, double> p1) { // is point under the line?
		if (p1.Y < (this->k*p1.X + this->b))
			return true;
		return false;
	}
};

struct myless {
	bool operator()(int a, int b) {
		if (arr[a].X != arr[b].X)
			return arr[a].X < arr[b].X;
		return arr[a].Y < arr[b].Y;
	}
};
bool isShell(int a, int b, int c) {
	line t(arr[a], arr[c]);
	if (t.is_under(arr[b]))
		return false;
	return true;
}
int main() {
	int n;
	cin >> n;
	int left_one = 0, right_one = 0;
	double left_min, right_min; // by the way, there should be "right_max", but is anyone cares?
	pair <double, double> p1;
	cin >> p1.X >> p1.Y;
	left_min = p1.X;
	right_min = p1.X;
	for (int i = 1; i < n; ++i) {
		double x, y;
		cin >> x >> y;
		if (x < left_min) {
			left_min = x;
			left_one = i;
		}
		if (x > right_min) {
			right_min = x;
			right_one = i;
		}
		pair <double, double> t(x, y);
		arr.push_back(t);
	}
	set <int, myless> upper;
	set <int, myless> lower;
	line mid(arr[left_one], arr[right_one]);
	for (int i = 0; i < n; ++i) { // my extremal points are in "upper"
		if (mid.is_under(arr[i]))
			lower.insert(i);
		else
			upper.insert(i);
	}
	vector <int> uS; //upperShell // I may be a #&*?, because of repeated code, but I'm too lazy to think and make everything nice<3
	for (auto i : upper) {
		if (uS.size() > 3) {
			if (isShell(uS[*(uS.end() - 2)], uS[*(uS.end() - 1)], i))
				uS.push_back(i);
			else {
				uS.erase(uS.end() - 1);
				uS.push_back(i);
			}
		}
		uS.push_back(i);
	}
	vector <int> lS; //lowerShell 
	lower.insert(left_one);
	lower.insert(right_one);
	for (auto i : lower) {
		if (lS.size() > 3) {
			if (!isShell(lS[*(lS.end() - 2)], lS[*(lS.end() - 1)], i))
				lS.push_back(i);
			else {
				lS.erase(lS.end() - 1);
				lS.push_back(i);
			}
		}
		lS.push_back(i);
	}
	// And, of course, I wrote all this comments 'cause of lack of attention
	for (int i = 0; i < uS.size(); ++i) {
		cout << arr[uS[i]].X << " " << arr[uS[i]].Y << endl;
	}
	for (int i = 1; i < lS.size() - 1; ++i) {
		cout << arr[lS[i]].X << " " << arr[lS[i]].Y << endl;
	}
	system("pause");
	return 0;
}