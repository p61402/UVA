// Run Time: 0.000
#include <iostream>
using namespace std;

int total_bottles(int num)
{
	int count = num;

	while (num >= 3)
	{
		count += num / 3;
		num = num / 3 + num % 3;
	}

	return count;
}

int main()
{
	int n;

	while (cin >> n)
		cout << total_bottles(n + 1) - 1 << endl;

	return 0;
}