// Run Time: 0.000
#include <iostream>
using namespace std;

int main()
{
	int n, x, y, diff, count, step;
	cin >> n;
	while (n--)
	{
		cin >> x >> y;
		diff = y - x;
		count = 0;
		step = 0;
		while (true)
		{
			count++;
			if (diff - count * 2 >= 0)
			{
				diff -= count * 2;
				step += 2;
			}
			else
				break;
		}

		if (diff > 0)
			if (diff > count)
				step += 2;
			else
				step += 1;

		cout << step << endl;
	}

	return 0;
}