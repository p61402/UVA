// Run Time: 0.220
#include <iostream>
using namespace std;

int f91(int n)
{
	if (n <= 100)
		return f91(f91(n + 11));
	else
		return n - 10;
}

int main()
{
	int num;

	while (true)
	{
		cin >> num;
		if (num == 0)
			break;
		else
			cout << "f91(" << num << ") = " << f91(num) << endl;
	}

	return 0;
}