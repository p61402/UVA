#include <iostream>
#include <map>
#include <climits>
#include <cmath>
using namespace std;

int main()
{
    int n, money, books[10005], min_diff, a, b;
    map<int, int> dict;

    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
            cin >> books[i];

        cin >> money;

        dict.clear();
        min_diff = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if (dict.find(books[i]) == dict.end())
                dict[money - books[i]] = books[i];
            else
            {
                if (abs(2 * books[i] - money) < min_diff)
                {
                    a = books[i];
                    b = money - books[i];
                    if (a > b)
                    {
                        int temp = a;
                        a = b;
                        b = temp;
                    }

                    min_diff = abs(a - b);
                }
            }
        }

        cout << "Peter should buy books whose prices are " << a << " and " << b << ".\n\n";
    }
    
    return 0;
}