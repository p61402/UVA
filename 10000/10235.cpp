// Run Time: 0.000
#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int x)
{
	if (x == 2)
		return true;

	if (x == 1 || x % 2 == 0)
		return false;

	for (int i = 3; i * i <= x; i += 2)
		if (x % i == 0)
			return false;
	return true;
}

bool isEmirp(int x)
{
	int y = x, a[10], count = 0, rev = 0;

	while (x)
	{
		a[count++] = x % 10;
		x /= 10;
	}

	for (int i = 0; i < count; i++)
		rev += a[i] * int(pow(10, count - i - 1));



	if (rev == y)
		return false;


	return isPrime(rev);
}

int main()
{
	int n;
	
	while (cin >> n)
		if (isPrime(n))
			if (isEmirp(n))
				cout << n << " is emirp.\n";
			else
				cout << n << " is prime.\n";
		else
			cout << n << " is not prime.\n";

	return 0;
}