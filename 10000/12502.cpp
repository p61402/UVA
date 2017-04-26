// Run Time: 0.000
#include <iostream>
using namespace std;

int main()
{
	int test_case;

	cin >> test_case;

	int x, y, z, a, b;

	while (test_case--)
	{
		cin >> x >> y >> z;

		cout << z * (2 * x - y) / (x + y) << endl;
	}
	
	return 0;
}