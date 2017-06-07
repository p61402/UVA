// Run Time: 0.510
#include <iostream>
#include <algorithm>
using namespace std;

int a[2000000];

int main()
{
	int n;

	while (true)
	{
		cin >> n;

		if (n == 0)
			break;

		for (int i = 0; i < n; i++)
			cin >> a[i];

		sort(a, a + n);

		for (int i = 0; i < n; i++)
		{
			cout << a[i];
			if (i != n - 1)
				cout << " ";
			else
				cout << "\n";
		}
	}

	return 0;
}