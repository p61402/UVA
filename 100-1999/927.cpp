// Run Time: 0.000
#include <iostream>
using namespace std;

int main()
{
	long long n, l, a[22], d, k, ans, ex;

	cin >> n;

	while (n--)
	{
		cin >> l;
		for (int i = 0; i <= l; i++)
			cin >> a[i];
		cin >> d >> k;
		
		long long count = 1, sum = d;
		while (k > sum)
			sum += d * (++count);

		ans = 0;
		ex = 1;
		for (int i = 0; i <= l; i++)
		{
			ans += a[i] * ex;
			ex *= count;
		}

		cout << ans << endl;
	}

	return 0;
}