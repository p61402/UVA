// Run Time: 0.000
#include <iostream>
using namespace std;

int main()
{
	int n = 1;
	int count = 0;
	int a[30];
	int input;

	while (n < 10001)
	{
		a[count++] = n;
		n *= 2;
	}

	a[count++] = 10001;

	int num_of_input = 0;
	while (true)
	{
		cin >> input;
		if (input < 0)
			break;

		for (int i = 0; i < count; i++)
			if (input <= a[i])
			{
				cout << "Case " << ++num_of_input << ": " << i << endl;
				break;
			}
	}

	return 0;
}