// Run Time: 0.020
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s[105];

	int num = 0;
	unsigned int max_length = 0;
	while (getline(cin, s[num]))
	{
		if (s[num].length() > max_length)
			max_length = s[num].length();
		num++;
	}

	for (unsigned int i = 0; i < max_length; i++)
	{
		for (int x = num - 1; x >= 0; x--)
			if (i < s[x].length())
				cout << s[x][i];
			else
				cout << " ";
		cout << endl;
	}

	return 0;
}