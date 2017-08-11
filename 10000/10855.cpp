// Run Time: 0.010
#include <iostream>
using namespace std;

char s1[500][500], s2[500][500], temp[500][500];

int find(int size1, int size2)
{
	int count = 0;
	for (int i = 0; i <= size1 - size2; i++)
	{
		for (int j = 0; j <= size1 - size2; j++)
		{
			bool not_match = false;
			for (int x = 0; x < size2; x++)
			{
				for (int y = 0; y < size2; y++)
				{
					if (s1[i + x][j + y] != s2[x][y])
					{
						not_match = true;
						break;
					}
				}

				if (not_match)
					break;
			}

			if (!not_match)
				count++;
		}
	}

	return count;
}

void rotate(int size)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			temp[i][j] = s2[i][j];

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			s2[j][size - i - 1] = temp[i][j];
}

int main()
{
	int N, n;

	while (cin >> N >> n)
	{
		if (N == 0 && n == 0)
			break;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> s1[i][j];

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> s2[i][j];

		int num_of_match[4] = { 0 };

		num_of_match[0] = find(N, n);

		for (int i = 1; i < 4; i++)
		{
			rotate(n);
			num_of_match[i] = find(N, n);
		}

		for (int i = 0; i < 4; i++)
		{
			cout << num_of_match[i];

			if (i != 3)
				cout << " ";
			else
				cout << endl;
		}
	}

	return 0;
}