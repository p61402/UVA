// Run Time: 0.040
#include <iostream>
using namespace std;

int flip_times(int a[], int n)
{
	int time = 0;

	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - 1 - i; j++)
			if (a[j] > a[j+1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				time++;
			}

	return time;
}

int main()
{
	int n, a[1000];
	
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
			cin >> a[i];

		cout << "Minimum exchange operations : " <<flip_times(a, n) << endl;
	}

	return 0;
}