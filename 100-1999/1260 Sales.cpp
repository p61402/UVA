#include <iostream>
using namespace std;

int main()
{
    int t, n, a[1005], b;

    cin >> t;

    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];

        b = 0;
        for (int i = 1; i < n; i++)
            for (int j = 0; j < i; j++)
                if (a[i] >= a[j])
                    b++;

        cout << b << endl;
    }

    return 0;
}