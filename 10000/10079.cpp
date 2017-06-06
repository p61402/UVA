// Run Time: 0.000
#include <iostream>
using namespace std;

int main()
{
	long long num;

	while (true)
	{
		cin >> num;

		if (num < 0)
			break;

		if (num == 0)
			cout << 1 << endl;
		else
			cout << 1 + (long long)(num * (num + 1)) / 2 << endl;
	}

	return 0;
}