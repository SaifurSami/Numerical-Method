#include <bits/stdc++.h>
using namespace std;
class LeastSquare {
private:
	double x [100], y [100], n, sumX = 0.0, sumY = 0.0, sumXX = 0.0, sumXY = 0.0;
public:
	LeastSquare () {}
	void getInput () {
		cout << "Enter the number of inputs = " <<endl;
		cin >> n;
		cout << "Enter the inputs = " <<endl;
		for ( int i = 0; i < n; i++) {
			cin >> x [i] >> y [i];
		}
		//for ( int i = 0; i < n; i++) {
		//	cout<<x[i]<<" "<<y[i]<<endl;
		//}
	}
	double summation () {
		for ( int i = 0; i < n; i++) {
            double temp = 0.0;
			sumX += x[i];
			sumXX += x[i] * x[i];
			sumY += y [i];
			temp = x[i] * y[i];
			sumXY = sumXY + temp;
			//cout<<temp<<" "<<sumXY<<endl;
		}
	}
	double con_m () {
		double m;
		m = sumXY * n;
		m -= ( sumX * sumY );
		m /= ( sumXX * n - sumX * sumX );
		return m;
	}
	double con_b () {
		double b = sumY - sumX * con_m ();
		b /= n;
		return b;
	}
	void calculation () {
		summation ();
		//cout<<sumX<<" "<<sumY<<" "<<sumXX<<" "<<sumXX<<endl;
		double a1 = con_m ();
		double a0 = con_b ();
		cout << "a0 = " << a0 << endl;
		cout << "a1 = " << a1 << endl;
		cout << "The Equation is =  " << a1 <<" * X + "<< a0 << endl;
	}
};
int main () {
	LeastSquare leastSquare;
	leastSquare.getInput ();
	leastSquare.calculation ();
}
