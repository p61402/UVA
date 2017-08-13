//Run Time: 0.000
#include <iostream>
using namespace std;

int main(void) 
{
	int n, count, current_sum, index;

	while (cin >> n)
	{
		count = 1;
		current_sum = 1;
		while (current_sum <= n)
			current_sum += (count++);

		current_sum -= count;
		index = n - current_sum;
		count--;

		cout << "TERM " << n << " IS ";
		if (count % 2 ==0)
			cout << index << "/" << count + 1 - index << endl;
		else
			cout << count + 1 - index << "/" << index << endl;
	}

	return 0;
}