// Run Time: 0.000
#include <iostream>
using namespace std;

int main()
{
	int test_case;

	cin >> test_case;

	int a, b;

	for (int n = 1; n <= test_case; n++)
	{
		cin >> a >> b;

		if (a % 2 == 0)
			a++;

		if (b % 2 == 0)
			b--;

		int sum = 0;

		for (int i = a; i <= b; i += 2)
			sum += i;

		cout << "Case " << n << ": " << sum << endl;
	}

	return 0;
}