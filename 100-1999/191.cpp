// Run Time: 0.000
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int test_case;

	cin >> test_case;

	double x0, y0, x1, y1, l, t, r, b;

	while (test_case--)
	{
		cin >> x0 >> y0 >> x1 >> y1 >> l >> t >> r >> b;

		if (l > r)
		{
			double temp = l;
			l = r;
			r = temp;
		}

		if (t < b)
		{
			double temp = b;
			b = t;
			t = temp;
		}

		// Horizontal Line
		if (x0 == x1)
		{
			if (x0 >= l && x0 <= r)
			{
				if ((y0 < b && y1 < b) || (y0 > t && y1 > t))
					cout << "F\n";
				else
					cout << "T\n";
			}
			else
			{
				cout << "F\n";
			}

			continue;
		}

		//Vertical Line
		if (y0 == y1)
		{
			if (y0 >= b && y0 <= t)
			{
				if ((x0 <= l && x1 <= l) || (x0 >= r && x1 >= r))
					cout << "F\n";
				else
					cout << "T\n";
			}
			else
			{
				cout << "F\n";
			}

			continue;
		}

		double slope = (y0 - y1) / (x0 - x1);

		if (t - y0 == slope * (l - x0) || b - y0 == slope * (l - x0) || t - y0 == slope * (r - x0) || b - y0 == slope * (r - x0))
			cout << "T\n";
		else if (x0 >= l && x0 <= r && x1 >= l && x1 <= r && y0 >= b && y0 <= t && y1 >= b && y1 <= t)
			cout << "T\n";
		else if (slope * (l - x0) + y0 >= min(y0, y1) && slope * (l - x0) + y0 <= max(y0, y1) && slope * (l - x0) + y0 >= b && slope * (l - x0) + y0 <= t)
			cout << "T\n";
		else if (slope * (r - x0) + y0 >= min(y0, y1) && slope * (r - x0) + y0 <= max(y0, y1) && slope * (r - x0) + y0 >= b && slope * (r - x0) + y0 <= t)
			cout << "T\n";
		else if ((b - y0) / slope + x0 >= min(x0, x1) && (b - y0) / slope + x0 <= max(x0, x1) && (b - y0) / slope + x0 >= l && (b - y0) / slope + x0 <= r)
			cout << "T\n";
		else if ((t - y0) / slope + x0 >= min(x0, x1) && (t - y0) / slope + x0 <= max(x0, x1) && (t - y0) / slope + x0 >= l && (t - y0) / slope + x0 <= r)
			cout << "T\n";
		else
			cout << "F\n";
	}

	return 0;
}