//Run Time: 0.000
#include <iostream>
#include <string>
using namespace std;

int main(void) 
{
	int test_case;
	string num;
	
	cin >> test_case;

	while (test_case--)
	{
		cin >> num;

		if (num == "1" || num == "4" || num == "78")
		{
			cout << "+\n";
			continue;
		}
		
		if (num.length() > 1 && num.substr(num.length() - 2, 2) == "35")
		{
			cout << "-\n";
			continue;
		}

		if (num[0] == '9' && num[num.length() - 1] == '4')
		{
			cout << "*\n";
			continue;
		}

		if (num.substr(0, 3) == "190")
		{
			cout << "?\n";
			continue;
		}

		cout << "?\n";
	}

	return 0;
}