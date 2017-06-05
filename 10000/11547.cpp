// Run Time: 0.000
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int test_case, num, result;
	cin >> test_case;

	while (test_case--)
	{
		cin >> num;

		result = (num * 567 / 9 + 7492) * 235 / 47 - 498;

		cout << abs((result / 10) % 10) << endl;
	}

	return 0;
}