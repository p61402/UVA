// Run Time: 0.020
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int a, b, temp, count;

	while (true)
	{
		cin >> a >> b;

		if (a == 0 && b == 0)
			break;

		count = 0;

		for (int i = a; i <= b; i++)
		{
			temp = sqrt(i);
			if (temp * temp == i)
				count++;
		}
		cout << count << endl;
	}

	return 0;
}