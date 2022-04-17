#include <bits/stdc++.h>
using namespace std;
class Trapezoidal {
private:
	double lower, upper, segment;
	double function ( double x) {
		return 1 / ( 1 + x * x );
	}
public:
	Trapezoidal () {}
	void input () {
		cout << "Enter the Range & segment = " << endl;
		cin >> lower >> upper >> segment;
	}
	double calculation () {
		double area = function (lower) + function (upper);
		double step = (upper - lower) / segment;
		for ( int i = 1; i < segment; i++) {
			area += ( 2 * function ( lower + i * step));
		}
		area *= (step / 2);
		return area;

	}
};
int main () {
	Trapezoidal trapezoidal;
	trapezoidal.input ();
	printf("The Area = %.8lf\n", trapezoidal.calculation ());

}
