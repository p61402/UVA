#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    long long a, b, num = 0, number_of_terms;

    while (cin >> a >> b)
    {
        if (a < 0 && b < 0)
            break;

        printf("Case %lld: A = %lld, limit = %lld, number of terms = ", ++num, a, b);

        number_of_terms = 0;

        while (a != 1 && a <= b)
        {
            if ((a & 1) == 0)
                a /= 2;
            else
                a = a * 3 + 1;

            number_of_terms++;
        }

        if (a == 1)
            cout << number_of_terms + 1 << endl;
        else
            cout << number_of_terms << endl;
    }

    return 0;
}