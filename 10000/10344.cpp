#include <iostream>
using namespace std;

int a[5];
int temp[5];
int solution[120][5];
int current_index = 0;
int used[5] = { false };
int count_permutation = 0;

bool backtracking(int i, int s)
{
	if (i == 5)
		if (s == 23)
			return true;
		else
			return false;

	return backtracking(i + 1, s + a[solution[current_index][i]]) || backtracking(i + 1, s - a[solution[current_index][i]]) || backtracking(i + 1, s * a[solution[current_index][i]]);
}

void permutation(int n)
{
	if (n == 5)
	{
		for (int a = 0; a < 5; a++)
			solution[count_permutation][a] = temp[a];
		count_permutation++;
		return;
	}

	for (int j = 0; j < 5; j++)
	{
		if (!used[j])
		{
			used[j] = true;
			temp[n] = j;
			permutation(n + 1);
			used[j] = false;
		}
	}
}

int main()
{
	permutation(0);

	while (true)
	{
		cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];

		if (a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 0 && a[4] == 0)
			break;

		bool found = false;

		for (int x = 0; x < 120; x++)
		{
			current_index = x;
			if (backtracking(1, a[solution[current_index][0]]))
			{
				found = true;
				break;
			}
		}

		if (found)
			cout << "Possible\n";
		else
			cout << "Impossible\n";
	}

	return 0;
}