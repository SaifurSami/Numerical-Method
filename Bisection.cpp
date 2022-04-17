#include<bits/stdc++.h>
using namespace std;
class Bisection {
private:
	const double eps = 0.0000000001;
	double root(double x) const
	{
		return x *x *x - x *x -1;
	}
public:
	Bisection() {}
	double calculation(double low, double hi) {
		double mid = hi;
		for(int i=0; i<1000000; i++) {
			mid = (low + hi) / 2.0;
			if(root(low) * root(mid) <0)
				hi = mid;
			else
				low = mid;
		}
		return mid;
	}

};
int main()  {
	//cin.tie(0)->sync_with_stdio(false);
	//cout << setprecision(10) << fixed;
	Bisection bisection;
	//cout<<bisection.calculation(10, -10) << endl;
	printf("The Root of the equation is = %.10lf\n", bisection.calculation(10, -10));
	return 0;
}
