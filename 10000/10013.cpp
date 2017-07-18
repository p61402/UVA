// Run Time: 0.920
#include <iostream>
#include <cstring>
using namespace std;

int a[2][1000000], result[1000000];

int main()
{
	int n, m, count, answer, carry;
	
	cin >> n;

	while (n--)
	{
		cin >> m;

		count = 0;

		while (m--)
		{
			cin >> a[0][count] >> a[1][count];
			count++;
		}

		carry = 0;
		memset(result, 0, sizeof(result));

		for (int i = count - 1; i >= 0; i--)
		{
			answer = a[0][i] + a[1][i] + carry;
			carry = answer / 10;
			result[i] = answer % 10;
		}

		if (carry == 1)
			cout << "1";


		for (int i = 0; i < count; i++)
			cout << result[i];

		cout << endl;

		if (n != 0)
			cout << endl;
	}
	
	return 0;
}