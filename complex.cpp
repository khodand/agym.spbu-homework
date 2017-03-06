#include <iostream>

using namespace std;

class complex {
public:
	double n;
	double m;

public:

	complex(int a, int b)
		:n(a), m(b){}

	complex(complex *A) {
		n = A->n;
		m = A->m;
	}

	double mod() {
		return sqrt(n * n + m * m);
	}

	complex operator=(complex A) {
		n = A.n;
		m = A.m;
		return *this;
	}

	complex operator-=(complex A) {
		n -= A.n;
		m -= A.m;
		return *this;
	}

	complex operator+=(complex B) {
		n += B.n;
		m += B.m;
		return *this;
	}

	complex operator*=(complex A) {
		double temp1, temp2;
		temp1 = n * A.n - m * A.m;
		temp2 = n * A.m + m * A.n;
		n = temp1;
		m = temp2;
		return *this;
	}

	complex operator/=(complex A) {
		double temp1, temp2;
		temp1 = (n * A.n + m * A.m) / (A.n * A.n + A.m * A.m);
		temp2 = (m * A.n - n * A.m) / (A.n * A.n + A.m * A.m);
		n = temp1;
		m = temp2;
		return *this;
	}

	double angle(double r) {
		double temp1 = n / r,
			temp2 = m / r,
			fi;

		if (temp2 >= 0) 
			fi = acos(temp1);
		else 
			fi = -acos(temp1);

		return fi;
	}
	
	void print1() {
		cout << n << " + " << m << "i";
	}

	void print2() {
		double r = mod();
		double fi = angle(r);
		cout << r << " * (cos(" << fi << ") + i*sin(" << fi << "))" << endl;
	}

	void print3() {
		double r = mod();
		double fi = angle(r);
		cout << r << " * e^(i*" << fi << ")" << endl;
	}

};

complex operator-( complex A, complex B) {
	return A -= B;
}

complex operator+(complex A, complex B) {
	return A += B;
}

complex operator*(complex A, complex B) {
	return A *= B;
}

complex operator/(complex A, complex B) {
	return A /= B;
}

bool operator==(complex A, complex B) {
	return B.n == A.n && B.m == A.m;
}

int main() {
	complex A(10, 13);
	complex B(21, 10);
	A += B;
	(A + B).print1();
	cout << endl;
	(A - B).print2();
	cout << endl;
	A.print3();
	cout << endl;
	system("pause");
	return 0;
}
