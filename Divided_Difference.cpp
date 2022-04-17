#include <bits/stdc++.h>
using namespace std;
int n;
double x [100], y [100][100];
class Divided_Difference {
public:
	Divided_Difference () {}
	double table () {
		for ( int i = 1; i < n; i++ ) {
			int ind1 = i, ind2 = 0;
			for ( int j = 0; j < n - i; j++ ) {
				y [j][i] = y [ j + 1 ][ i - 1 ] - y [ j ][ i - 1 ];
				if ( j != 0 )
				ind1++, ind2++;
				y [j][i] /= (x [ind1] - x [ind2]);

			}
		}
	}
	double claculation (double req) {
		double sum = y [0][0];
		//double u = find_U ();
		for (int i = 1; i < n; ++i) {
			double temp = 1.0;
			for ( int j = 0; j < i; j++) {
                //temp = 1.0;
				temp *= ( req - x [j]);
			}
			temp *= y [0][i];
			sum += temp;
		}
		return sum;
	}
};
int main () {
	Divided_Difference divided_difference;
	cout << "Enter the number of inputs = ";
	cin >> n;
	cout << endl << "Enter the X and Y = ";
	for (int i = 0; i < n; ++i)
	{
		cin >> x [i] >> y [i][0];
	}
	cout << endl << "Enter the required value = ";

	double req;
	cin >> req;
	divided_difference.table();
	for ( int i=0;i<n;i++)
	{
        for(int j=0;j<n;j++)
        cout<<y[i][j]<<" ";
        cout<<endl;
	}
	cout<<endl;
	printf("The value of the fucntion is = %.8lf\n", divided_difference.claculation (req));
}
