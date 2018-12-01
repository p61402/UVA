#include <iostream>
using namespace std;

int main()
{
    int t, n, scarecrows;
    char a[105];

    cin >> t;

    for (int k = 1; k <= t; k++)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        a[n] = a[n + 1] = '#';

        if (n == 1)
        {
            if (a[0] == '.')
                scarecrows = 1;
            else
                scarecrows = 0;
            cout << "Case " << k << ": " << scarecrows << endl;
            continue;
        }

        scarecrows = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i - 1] == '.')
            {
                a[i - 1] = a[i] = a[i + 1] = '#';
                scarecrows++;
            }
        }

        cout << "Case " << k << ": " << scarecrows << endl;
    }

    return 0;
}