// Run Time: 0.000
#include <iostream>
#include <string>
using namespace std;

int hexa_list[] = { 0, 1, 1, 2, 1, 2, 2, 3, 1, 2 };

int dec_to_bin_and_count_one(int n)
{
	int numOfones = 1;

	while (n != 1)
	{
		numOfones += n % 2;
		n /= 2;
	}

	return numOfones;
}

int dec_to_hexa_and_count_one(int n)
{
	int numOfones = 0;
	string s = to_string(n);

	for (int i = 0; i < s.length(); i++)
		numOfones += hexa_list[s[i] - '0'];

	return numOfones;
}

int main()
{
	int test_case;
	cin >> test_case;

	int num;
	while (test_case--)
	{
		cin >> num;

		cout << dec_to_bin_and_count_one(num) << " " << dec_to_hexa_and_count_one(num) << endl;
	}

	return 0;
}
