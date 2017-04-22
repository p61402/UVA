// Run Time: 0.000
#include <iostream>
#include <iomanip>
using namespace std;

int sum_of_divisors(int n)
{
	int sum = 0;

	for (int i = 1; i <= n / 2; i++)
		if (n % i == 0)
			sum += i;

	return sum;
}

int analyze_the_number(int n)
{
	int value = sum_of_divisors(n);

	if (value > n)
		return 1;
	else if (value < n)
		return -1;
	else
		return 0;
}

int main()
{
	int num;

	cout << "PERFECTION OUTPUT\n";

	while (true)
	{
		cin >> num;

		if (num == 0)
			break;

		cout << setfill(' ') << setw(5);
		cout << num << "  ";

		int flag = analyze_the_number(num);

		if (flag == 1)
			cout << "ABUNDANT\n";
		else if (flag == -1)
			cout << "DEFICIENT\n";
		else
			cout << "PERFECT\n";
	}

	cout << "END OF OUTPUT\n";

	return 0;
}