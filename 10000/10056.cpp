// Run Time: 0.000
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	int test_case;
	double num, p, target;
	cin >> test_case;
	cout << fixed << showpoint << setprecision(4);

	while (test_case--)
	{
		cin >> num >> p >> target;

		double x = p * pow(1 - p, target - 1) / (1 - pow(1 - p, num));

		if (p == 0)
			cout << "0.0000" << endl;
		else
			cout << round(x * 10000) / 10000 << endl;
	}

	return 0;
}