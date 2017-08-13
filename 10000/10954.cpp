//Run Time: 0.010
#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int main(void) 
{
	int n, x, num1, num2, cost;

	while (cin >> n)
	{
		if (n == 0)
			break;

		priority_queue<int, vector<int>, greater<int>> pq;

		for (int i = 0; i < n; i++)
		{
			cin >> x;
			pq.push(x);
		}
		
		cost = 0;
		while (pq.size() > 1)
		{
			num1 = pq.top();
			pq.pop();
			num2 = pq.top();
			pq.pop();
			
			cost += num1 + num2;
			pq.push(num1 + num2);
		}

		cout << cost << endl;
	}

	return 0;
}