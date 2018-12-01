#include <iostream>
using namespace std;

bool lose(char p1, char p2)
{
    if (p1 == 'R' && p2 == 'P' || p1 == 'P' && p2 == 'S' || p1 == 'S' && p2 == 'R')
        return true;
    return false;
}

int main()
{
    int t, r, c, n;
    char a[105][105], next_a[105][105];
    
    cin >> t;

    while (t--)
    {
        cin >> r >> c >> n;

        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
            {
                cin >> a[i][j];
                next_a[i][j] = a[i][j];
            }
        
        while(n--)
        {
            for (int i = 0; i < r; i++)
                for (int j = 0; j < c; j++)
                {
                    if (i - 1 >= 0 && lose(a[i][j], a[i - 1][j]))
                        next_a[i][j] = a[i - 1][j];
                    else if (i + 1 < r && lose(a[i][j], a[i + 1][j]))
                        next_a[i][j] = a[i + 1][j];
                    else if (j - 1 >= 0 && lose(a[i][j], a[i][j - 1]))
                        next_a[i][j] = a[i][j - 1];
                    else if (j + 1 < c && lose(a[i][j], a[i][j + 1]))
                        next_a[i][j] = a[i][j + 1];
                }
            
            for (int i = 0; i < r; i++)
                for (int j = 0; j < c; j++)
                    a[i][j] = next_a[i][j];
        }

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
                cout << a[i][j];
            cout << endl;
        }

        if (t)
            cout << endl;
    }

    return 0;
}