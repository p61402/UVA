// Run Time: 0.000
#include <iostream>
using namespace std;

int main()
{
	int T, N, last_wall, this_wall, high_jumps, low_jumps;

	cin >> T;

	for (int i = 1; i <= T; i++)
	{
		cin >> N;
		N--;

		cin >> last_wall;

		high_jumps = 0;
		low_jumps = 0;

		while (N--)
		{
			cin >> this_wall;

			if (this_wall > last_wall)
				high_jumps++;
			else if (this_wall < last_wall)
				low_jumps++;

			last_wall = this_wall;
		}

		cout << "Case " << i << ": " << high_jumps << " " << low_jumps << endl;
	}

	return 0;
}