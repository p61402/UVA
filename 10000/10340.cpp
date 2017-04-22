// Run Time: 0.000
#include <iostream>
#include <string>
using namespace std;

bool subsequence(string s, string t)
{
	unsigned int pos_s = 0;

	for (unsigned int pos_t = 0; pos_t < t.length(); pos_t++)
		if (s[pos_s] == t[pos_t])
			pos_s++;

	if (pos_s == s.length())
		return true;
	else
		return false;
}

int main()
{
	string s, t, buffer;

	while (cin >> s >> t)
	{
		getline(cin, buffer);

		if (subsequence(s, t))
			cout << "Yes\n";
		else
			cout << "No\n";
	}

	return 0;
}