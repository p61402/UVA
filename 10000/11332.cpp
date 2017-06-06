// Run Time: 0.000
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int num;

	while (true)
	{
		cin >> num;

		if (num == 0)
			break;

		while (num / 10 > 0)
		{
			string s = to_string(num);

			num = 0;
			for (unsigned int i = 0; i < s.length(); i++)
				num += s[i] - '0';
		}

		cout << num << endl;
	}

	return 0;
}