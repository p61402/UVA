#include <iostream>
using namespace std;

int matrix1[10005][10005], matrix2[10005][10005];

int main()
{
    int m, n, r, a[100], v, indexs[100], values[100], c;

    while (cin >> m >> n)
    {
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
                matrix1[i][j] = 0;
            
            cin >> r;

            for (int j = 1; j <= r; j++)
                cin >> a[j];

            for (int j = 1; j <= r; j++)
            {
                cin >> v;
                matrix1[i][a[j]] = v;
            }
        }

        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                matrix2[j][i] = matrix1[i][j];

        cout << n << ' ' << m << endl;
        for (int i = 1; i <= n; i++)
        {
            c = 0;
            for (int j = 1; j <= m; j++)
            {
                if (matrix2[i][j])
                {
                    indexs[c] = j;
                    values[c] = matrix2[i][j];
                    c++;
                }
            }

            cout << c;
            for (int j = 0; j < c; j++)
                cout << " " << indexs[j];
            cout << endl;

            for (int j = 0; j < c; j++)
            {
                cout << values[j];
                if (j != c - 1)
                    cout << " ";
            }
            cout << endl;
        }
    }

    return 0;
}