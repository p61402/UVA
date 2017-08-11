// Run Time: 0.000
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n, numerator, denominator;

	while (cin >> n)
	{
		string ans[300];
		int count = 0;
		for (int i = n + 1; i <= 2 * n; i++)
		{
			numerator = i - n;
			denominator = i * n;

			if (denominator % numerator == 0)
			{
				denominator /= numerator;
				ans[count++] = "1/" + to_string(n) + " = 1/" + to_string(denominator) + " + 1/" + to_string(i);
			}
		}

		cout << count << endl;
		for (int i = 0; i < count; i++)
		{
			cout << ans[i] << endl;
		}
	}

	return 0;
}