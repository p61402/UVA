//Run Time: 0.000
#include <iostream>
#include <string>
using namespace std;

int main(void) 
{
	int n;

	while (cin >> n)
	{
		if (n == 0)
			break;

		string s;

		while (n != 1)
		{
			s.insert(0, to_string(n % 2));
			n /= 2;
		}

		s.insert(0, "1");

		int count_one = 0;
		for (int i = 0; i < s.length(); i++)
			if (s[i] == '1')
				count_one++;

		cout << "The parity of " << s << " is " << count_one << " (mod 2).\n";
	}

	return 0;
}