// Run Time: 0.030
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	long long n, x;

	while (true)
	{
		cin >> n;

		if (n == 0)
			break;

		x = sqrt(n);

		if (x * x == n)
			cout << "yes\n";
		else
			cout << "no\n";
	}

	return 0;
}