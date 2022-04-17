#include <bits/stdc++.h>
using namespace std;
class Simpson {
private:
	double lower, upper, segment;
	double function ( double x ) {
		return log( x );
	}
public:
	Simpson () {}
	void getInput () {
		cout << "Enter the Range & segment = " << endl;
		cin >> lower >> upper >> segment;
	}
	double calculation () {
		double area = function ( lower ) + function ( upper );
		double step = ( upper - lower ) / segment;
		for ( int i = 1; i < segment; i++ ) {
			if ( i % 2 ) {
				area += ( 4 * function ( lower + i * step));
			}
			else
				area += ( 2 * function ( lower + i * step));
		}
		area *= (step / 3);
		return area;

	}
};
int main () {
	Simpson simpson;
	simpson.getInput();
	printf("The Area = %.8lf\n", simpson.calculation ());

}
