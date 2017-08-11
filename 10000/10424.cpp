// Run Time: 0.000
#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
using namespace std;

int main()
{
	string s1, s2;
	int n1, n2;

	while (getline(cin, s1) && getline(cin, s2))
	{
		n1 = 0;
		n2 = 0;

		for (unsigned int i = 0; i < s1.length(); i++)
			if (isalpha(s1[i]))
				if (isupper(s1[i]))
					n1 += s1[i] - 'A' + 1;
				else
					n1 += s1[i] - 'a' + 1;

		for (unsigned int i = 0; i < s2.length(); i++)
			if (isalpha(s2[i]))
				if (isupper(s2[i]))
					n2 += s2[i] - 'A' + 1;
				else
					n2 += s2[i] - 'a' + 1;

		while (n1 / 10 != 0)
		{
			int temp = 0;
			while (n1)
			{
				temp += n1 % 10;
				n1 /= 10;
			}
			n1 = temp;
		}

		while (n2 / 10 != 0)
		{
			int temp = 0;
			while (n2)
			{
				temp += n2 % 10;
				n2 /= 10;
			}
			n2 = temp;
		}

		if (n1 > n2)
			cout << setiosflags(ios::fixed | ios::showpoint) << setprecision(2) << 100 * (double)n2 / n1 << " %\n";
		else
			cout << setiosflags(ios::fixed | ios::showpoint) << setprecision(2) << 100 * (double)n1 / n2 << " %\n";
	}

	return 0;
}