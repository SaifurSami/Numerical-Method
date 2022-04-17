#include<bits/stdc++.h>
using namespace std;
double x [100], y [100], n;
class Lagrange {
private:
	double function (double req, int indx) {
		double func;
		double temp = 1.0;
		for ( int i = 0; i < n; ++i ) {
			//double temp;
			if ( i != indx ) {
				temp *= (req - x [i]);
			}
		}
		for ( int i = 0; i < n; ++i ) {
			if ( i != indx) {
				temp /= ( x [indx] - x [i]);
			}
		}
		func = temp * y [indx];
		return func;
	}
public:
	Lagrange () {}
	double calculation (double req) {
		double result = 0.0;
		for (int i = 0; i < n; ++i) {
			result += function (req, i);
		}
		return result;
	}
};
int main () {
	Lagrange lagrange;
	cout << "Enter the number of inputs = " << endl;
	cin >> n;
	cout << "Enter X  & Y = " << endl;
	for ( int i = 0; i < n; i++) {
		cin >> x [i] >> y [i];
	}
	cout << "Enter the required value = " << endl;
	double req;
	cin >> req;
	printf("The value of f(x) = %.8lf\n", lagrange.calculation(req));
}
