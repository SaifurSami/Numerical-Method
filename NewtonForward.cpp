#include <bits/stdc++.h>
using namespace std;
double n, h, req, x [100], y [100][100];
class NewtonForward {
private:

public:
    NewtonForward () {}
	int factorial (int n) {
		if (n <= 0)
			return 1;
		return n * factorial (n-1);
	}

	double for_dif (int n)  {
		for(int i = 1; i < n; i++) {
			for (int j = 0; j < n-i; j++) {
				y [j][i] = y [j + 1][i - 1] - y [j][i - 1];
			}
		}
	}
	/*double find_U (double req) {
		double temp = req - x [0];
		temp /= h;
		return temp;
	}*/
	double claculation (double req) {
		double sum = y [0][0];
		double u = req - x [0];
		u /= (x [1] - x [0]);
		double temp;
		for (int i = 1; i < n; i++)
		{
            double t = u;
			if (i > 1) {
				for (int j = 1; j < i; j++) {
					t *= (u - j);
				}
			}
			temp = (t * y [0][i]);
			temp /= factorial (i);
			sum += temp;
		}
		return sum;
	}
};
int main() {
    NewtonForward newtonForward;
    //cout<<newtonForward.factorial(5)<<endl;

	cout << "Enter the number of inputs = ";
	cin >> n;
	cout << endl << "Enter the X and Y = ";
	for (int i = 0; i < n; ++i)
	{
		cin >> x [i] >> y [i][0];
	}
	//x0 = x [0];
	//y0 = y [0][0];
	//h = x [1] - x [0];
	cout << endl << "Enter the required value = ";
	cin >> req;
	newtonForward.for_dif(n);
	//newtonForward.find_U(req);
	//cout<<newtonForward.find_U(req)<<endl;
	/*for(int i=0;i<n;i++){
	for(int j=0;j<n;j++)
	{
        cout<<y[i][j]<<" ";
	}
	cout<<endl;
	}*/
	printf("The value of the fucntion is = %.8lf\n", newtonForward.claculation (req));
}
