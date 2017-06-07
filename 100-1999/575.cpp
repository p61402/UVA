// Run Time: 0.000
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	string s;

	while (true)
	{
		cin >> s;

		if (s == "0")
			break;

		int num = 0;
		unsigned int len = s.length();
		for (unsigned int i = 0; i < len; i++)
		{
			num += (s[i] - '0') * (pow(2, len - i) - 1);
		}

		cout << num << endl;
	}

	return 0;
}