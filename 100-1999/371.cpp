// Run Time: 0.050
#include <iostream>
using namespace std;

int Ackermann_Function(long long i)
{
	if (i == 1LL)
		return 3;

	int length = 0;

	while (i != 1)
	{
		if (i % 2 == 0)
			i /= 2;
		else
			i = i * 3 + 1;
			
		length++;
	}

	return length;
}

int main()
{
	int L, H;

	while (true)
	{
		cin >> L >> H;

		if (L > H)
		{
			int temp = L;
			L = H;
			H = temp;
		}
		
		if (L == 0 && H == 0)
			break;

		int value, maximum = 0, max_index;
		for (int i = H; i >= L; i--)
		{
			value = Ackermann_Function(i);
			if (value >= maximum)
			{
				maximum = value;
				max_index = i;
			}
		}

		cout << "Between " << L << " and " << H << ", " << max_index << " generates the longest sequence of " << maximum << " values.\n";
	}

	return 0;
}