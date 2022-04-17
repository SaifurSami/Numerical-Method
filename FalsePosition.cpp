#include <bits/stdc++.h>
using namespace std;
class FalsePosition {
private:
	const double eps = 0.0000000001;
	double root(double x) const
	{
		return x *x *x - x *x -1;
	}
public:
	FalsePosition() {}
	double calculation(double low, double hi) {
		double newroot = hi;
		for(int i=0; i<1000000; i++) {
			newroot = (low * root(hi) -  hi * root(low))/(root(hi) - root(low));
			if(root(low) * root(hi) <0)
				hi = newroot;
			else
				low = newroot;
		}
		return newroot;
	}
};
int main() {
    FalsePosition falseposition;
    printf("The root of the equation is = %.10lf\n", falseposition.calculation(10, -10));
    return 0;
}
