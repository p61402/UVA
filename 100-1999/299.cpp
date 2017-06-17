// Run Time: 0.000
#include <iostream>
using namespace std;

int main()
{
	int n, x, a[50], temp, count;

	cin >> n;

	while (n--)
	{
		cin >> x;
		for (int i = 0; i < x; i++)
			cin >> a[i];

		count = 0;
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < x - i - 1; j++)
			{
				if (a[j] > a[j + 1])
				{
					count++;
					temp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = temp;
				}
			}
		}

		cout << "Optimal train swapping takes " << count << " swaps.\n";
	}

	return 0;
}