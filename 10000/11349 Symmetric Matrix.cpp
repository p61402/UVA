#include <iostream>
using namespace std;

int main()
{
    long long t, n, a[105][105];
    char c;
    bool valid;

    cin >> t;

    for (int x = 1; x <= t; x++)
    {
        cin >> c >> c >> n;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> a[i][j];

        valid = true;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i][j] < 0 || a[i][j] != a[n - 1 - i][n - 1 - j])
                {
                    valid = false;
                    break;
                }
            }

            if (!valid)
                break;
        }

        cout << "Test #" << x << ": ";
        if (valid)
            cout << "Symmetric.\n";
        else
            cout << "Non-symmetric.\n";
    }

    return 0;
}