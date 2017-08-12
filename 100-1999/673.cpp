//Run Time: 0.070
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void) 
{
	int test_case;
	string s;

	cin >> test_case;
	getline(cin, s);

	while (test_case--)
	{
		getline(cin, s);
		stack<char> char_stack;
		bool is_legal = true;

		for (unsigned int i = 0; i < s.length(); i++)
		{
			if (s[i] == '(' || s[i] == '[')
				char_stack.push(s[i]);
			else
			{
				if (!char_stack.empty())
					if ((s[i] == ')' && char_stack.top() == '(') || (s[i] == ']' && char_stack.top() == '['))
					{
						char_stack.pop();
						continue;
					}
				is_legal = false;
				break;
			}
		}

		if (!char_stack.empty())
			is_legal = false;

		if (is_legal)
			cout << "Yes\n";
		else
			cout << "No\n";
	}

	return 0;
}