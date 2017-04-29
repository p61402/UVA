// Run Time: 0.020
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N;
	bool is_first = true;

	while (true)
	{
		cin >> N;

		if (N == 0)
			break;

		if (!is_first)
			cout << endl;

		is_first = false;

		bool found = false;

		int num1, num2;

		for (int i = 1; i < 100000; i++)
		{
			if (i * N >= 100000)
				break;

			int table[10] = { 0 };

			num1 = i * N;
			num2 = i;

			for (int k = 0; k < 5; k++)
			{
				table[num1 % 10]++;
				table[num2 % 10]++;
				num1 /= 10;
				num2 /= 10;
			}

			bool is_duplicated = false;

			for (int t = 0; t < 10; t++)
			{
				if (table[t] != 1)
				{
					is_duplicated = true;
				}
			}

			if (!is_duplicated)
			{
				string s1 = to_string(i * N), s2 = to_string(i);

				for (int a = 0; a < 5 - s1.length(); a++)
					s1.insert(0, "0");

				for (int b = 0; b < 5 - s2.length(); b++)
					s2.insert(0, "0");

				cout << s1 << " / " << s2 << " = " << N << endl;
				found = true;
			}
		}

		if (!found)
			cout << "There are no solutions for " << N << ".\n";
	}

	return 0;
}