// Run Time: 0.000
#include <iostream>
#include <string>
using namespace std;

int find(char arr[], int len, char target)
{
	for (int i = 0; i < len; i++)
		if (arr[i] == target)
			return i;
	return -1;
}

int main()
{
	char table[] = { '`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=',
					 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '[', ']', '\\',
					 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ';', '\'',
					 'Z', 'X', 'C', 'V', 'B', 'N', 'M', ',', '.', '/' };

	string line;

	while (getline(cin, line))
	{
		for (unsigned int i = 0; i < line.length(); i++)
		{
			if (line[i] == ' ')
				cout << ' ';
			else
				cout << table[find(table, 47, line[i]) - 1];
		}

		cout << endl;
	}

	return 0;
}