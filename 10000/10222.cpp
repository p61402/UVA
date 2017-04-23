// Run Time: 0.000
#include <iostream>
#include <string>
using namespace std;

int main()
{
	char T[] = "1234567890-=qwertyuiop[]asdfghjkl;'zxcvbnm,./";
	string s;

	getline(cin, s);

	for (int i = 0; i < s.length(); i++)
	{
		s[i] = tolower(s[i]);

		if (s[i] == ' ')
			cout << ' ';
		else
			for (int j = 0; T[j]; j++)
				if (T[j] == s[i])
					cout << T[j - 2];
	}
	cout << endl;

	return 0;
}