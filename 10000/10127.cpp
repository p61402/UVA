// Run Time: 0.000
#include <iostream>
using namespace std;

int main()
{
	int n, p, count;

	while (cin >> n)
	{
		p = 1;
		count = 1;

		while (p % n)
		{
			count++;
			p = (p % n) * 10 + 1;
		}

		cout << count << endl;
	}

	return 0;
}