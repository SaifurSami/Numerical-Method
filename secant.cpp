#include<bits/stdc++.h>
using namespace std;
class Secant {
private:
	const double eps = 0.00000001;
	double function (double x) {
		return x * x * x + x * x - 1;
	}
public:
	Secant () {}
	double calculation () {
		double x0 = 0.1;
		double x1 = 0.5;
		double h = function (x1) * (x0 - x1) / (function (x0) - function (x1));
		double x2 = x1 - h;
		while(abs (h) >= eps) {
			h = function (x1) * (x0 - x1) / (function (x0) - function (x1));
			x2 = x1 - h;
			x0 = x1;
			x1 = x2;

		}
		return x2;
	}

};
int main( ) {
	Secant secant;
	printf("%.8lf\n", secant.calculation ());
}
