#include <bits/stdc++.h>
using namespace std;

class NewtonForwad {
private:
	const double x0, y0, n, h, req, x [100], y [100];
public:
	NewtonForwad () {}
	int factorial (int n) {
		if (n <= 0)
			return 1;
		return factorial (n) * factorial (n-1);
	}

	double for_dif (int n)  {
		for(int i = 1; i < n; i++) {
			for (int j = 0; j < n-i; j++) {
				forward [j][i] = forward [j + 1][i - 1] - forward [j][i - 1];
			}
		}
	}
	double find_U () {
		double temp = req - x0;
		temp /= h;
		return temp;
	}
	double claculation () {
		double sum = y0;
		double u = find_U ();
		double temp;
		for (int i = 1; i < 4; ++i)
		{
			if (i > 1) {
				for (int j = 1; j < i; j++) {
					u *= (u - j)
				}
			}
			temp = (u * forward [0][i]);
			temp /= factorial (i);
			sum += temp;
		}
		return sum;
	}
};
int main() {
	cout << "Enter the number of inputs = ";
	cin >> n;
	cout << endl << "Enter the X and Y = ";
	for (int i = 0; i < n; ++i)
	{
		cin >> x [i] >> y [i];
	}
	x0 = x [0];
	y0 = y [0];
	h = x [1] - x [0];
	cout << endl << "Enter the required value = ";
	cin >> req;
	NewtonForwad newtonForwad;
	printf("The value of the fucntion is = %.8lf\n", newtonForwad.claculation ());
}
