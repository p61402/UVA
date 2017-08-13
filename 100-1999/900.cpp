//Run Time: 0.000
#include <iostream>
using namespace std;

int main(void) 
{
	long long fib[51];
	int n;

	fib[1] = 1;
	fib[2] = 2;
	for (int i = 3; i < 51; i++)
		fib[i] = fib[i - 1] + fib[i - 2];

	while (cin >> n)
	{
		if (n == 0)
			break;

		cout << fib[n] << endl;
	}

	return 0;
}