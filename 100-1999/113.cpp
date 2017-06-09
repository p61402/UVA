// Run Time: 0.000
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	double n, p;

	while (cin >> n >> p)
		cout << setiosflags(ios::fixed) << setprecision(0) << pow(p, 1 / n) << endl;

	return 0;
}