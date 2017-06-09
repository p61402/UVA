// Run Time: 0.000
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isPalindrome(string s)
{
	string original = s;
	reverse(s.begin(), s.end());
	if (original == s)
		return true;
	else
		return false;
}

int main()
{
	int test_case;
	unsigned int num;

	cin >> test_case;

	while (test_case--)
	{
		cin >> num;
		int count;
		for (count = 0; count < 1000; count++)
		{
			if (isPalindrome(to_string(num)))
				break;
			else
			{
				string adder = to_string(num);
				reverse(adder.begin(), adder.end());
				num += stoi(adder);
			}
		}

		cout << count << " " << num << endl;
	}

	return 0;
}