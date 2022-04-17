#include <bits/stdc++.h>
using namespace std;
class FlasePosition {
private:
	const double eps = 0.0000000001;
	double root(double x) const
	{
		return x *x *x - x *x -1;
	}
public:
	FlasePosition() {}
	double calculation(double low, double hi) {
		double mid = hi;
		for(int i=0; i<1000000; i++) {
			mid = (low * root(hi) -  hi * root(low))/(root(hi) - root(low));
			if(root(low) * root(hi) <0)
				hi = mid;
			else
				low = mid;
		}
		return mid;
	}
};