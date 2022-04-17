#include<bits/stdc++.h>
using namespace std;
class NewtonRaphson {
private:
	const double eps = 0.00000001;
	double f (double x) const {
		return x * x * x + x * x - 1;
	}
	double fbar (double x) const {
		return 3 * x *x + 2 * x;
	}
public:
	NewtonRaphson () {}
	double calculation () {
		double x = 0.50;
		double h = f (x) / fbar (x);
		while(abs (h) >= eps) {
			h =  (double)f (x) / fbar (x);
			x = x - h;
		}
		return x;
	}
};
int main() {
	NewtonRaphson newtonRaphson;
	printf("The root of the equation is = %.8lf \n", newtonRaphson.calculation ());
}
