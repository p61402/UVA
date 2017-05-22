// Run Time: 0.000
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int test_case;
	string s;

	cin >> test_case;

	for (int t = 1; t <= test_case; t++)
	{
		cout << "Case #" << t << ":" << endl;
		cin >> s;
		int status[50];
		status[0] = 0;
		for (unsigned int i = 1; i < s.length(); i++)
		{
			if ((s[i - 1] == 'R' && s[i] == 'R') || (s[i - 1] == 'R' && s[i] == 'C'))
				status[i] = status[i - 1] + 1;
			else if ((s[i - 1] == 'C'&&s[i] == 'F') || (s[i - 1] == 'F'&&s[i] == 'F'))
				status[i] = status[i - 1] - 1;
			else
				status[i] = status[i - 1];
		}

		int current_max = 0;
		for (unsigned int i = 0; i < s.length(); i++)
			if (status[i] > current_max)
				current_max = status[i];

		int minimum = 100;
		for (unsigned int i = 0; i < s.length(); i++)
			if (status[i] < minimum)
				minimum = status[i];

		while (current_max >= minimum)
		{
			int max_index;
			for (unsigned int i = s.length() - 1; i >= 0; i--)
				if (status[i] == current_max)
				{
					max_index = i;
					break;
				}


			cout << "| ";
			for (unsigned int i = 0; i < s.length(), i <= max_index; i++)
			{
				if (status[i] == current_max)
					if (s[i] == 'R')
						cout << '/';
					else if (s[i] == 'C')
						cout << '_';
					else
						cout << '\\';
				else
					cout << ' ';
			}
			cout << endl;
			current_max--;
		}
		
		cout << "+--";
		for (unsigned int i = 0; i < s.length(); i++)
			cout << '-';
		cout << endl << endl;
	}

	return 0;
}