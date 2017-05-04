// Run Time: 0.000
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int test_case;

	cin >> test_case;

	long long n;

	while (test_case--)
	{
		cin >> n;

		cout << int((sqrt(1 + 8 * n) - 1) / 2) << endl;
	}

	return 0;
}