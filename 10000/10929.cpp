// Run Time: 0.020
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	int odd_sum, even_sum;

	while (true)
	{
		cin >> s;

		if (s == "0")
			break;

		odd_sum = 0;
		even_sum = 0;

		for (unsigned int i = 0; i < s.length(); i += 2)
			odd_sum += s[i] - '0';

		for (unsigned int i = 1; i < s.length(); i += 2)
			even_sum += s[i] - '0';

		if ((odd_sum - even_sum) % 11 == 0)
			cout << s << " is a multiple of 11.\n";
		else
			cout << s << " is not a multiple of 11.\n";
	}

	return 0;
}