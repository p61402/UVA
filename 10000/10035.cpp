// Run Time: 0.000
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int num1, num2;

	while (true)
	{
		cin >> num1 >> num2;

		if (num1 == 0 && num2 == 0)
			break;

		string s1 = to_string(num1), s2 = to_string(num2);

		if (s1.length() > s2.length())
		{
			int difference_of_length = s1.length() - s2.length();
			for (int i = 0; i < difference_of_length; i++)
				s2.insert(0, "0");
		}
		else
		{
			int difference_of_length = s2.length() - s1.length();
			for (int i = 0; i < difference_of_length; i++)
				s1.insert(0, "0");
		}

		int len = s1.length();
		int carry = 0;
		int count_carry = 0;

		for (int i = len - 1; i >= 0; i--)
		{
			if (s1[i] - '0' + s2[i] - '0' + carry >= 10)
			{
				count_carry++;
				carry = 1;
			}
			else
			{
				carry = 0;
			}
		}

		if (count_carry > 0)
			if (count_carry > 1)
				cout << count_carry << " carry operations.\n";
			else
			        cout << "1 carry operation.\n";
		else
			cout << "No carry operation.\n";
	}

	return 0;
}
