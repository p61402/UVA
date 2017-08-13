//Run Time: 0.000
#include <iostream>
#include <algorithm>
using namespace std;

int main(void) 
{
	int test_case;
	long long a[3];

	cin >> test_case;

	for (int i = 0; i < test_case; i++)
	{
		cin >> a[0] >> a[1] >> a[2];

		sort(a, a + 3);

		cout << "Case " << i + 1 << ": ";
		if (a[0] + a[1] <= a[2])
			cout << "Invalid\n";
		else if (a[0] == a[1] && a[1] == a[2])
			cout << "Equilateral\n";
		else if (a[0] == a[1] || a[1] == a[2])
			cout << "Isosceles\n";
		else
			cout << "Scalene\n";
	}

	return 0;
}