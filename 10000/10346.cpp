// Run Time: 0.000
#include <iostream>
using namespace std;

int main()
{
	int n, k, count;

	while (cin >> n >> k)
	{
		count = 0;
		
		while (n / k > 0)
		{
			count += n - n % k;
			n = n / k + n % k;
		}

		count += n;

		cout << count << endl;
	}

	return 0;
}