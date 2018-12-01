#include <iostream>
using namespace std;

void rotate(int x[][15], int y[][15], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            y[j][n-i-1] = x[i][j];
}

void reflect(int x[][15], int y[][15], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            y[n-i-1][j] = x[i][j];
}

bool same(int x[][15], int y[][15], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (x[i][j] != y[i][j])
                return false;
    return true;
}

int main()
{
    int n, a[15][15], b[15][15], t1[15][15], t2[15][15], t3[15][15], t4[15][15], num = 1;
    char c;

    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> c;
                if (c == 'X')
                    a[i][j] = 1;
                else
                    a[i][j] = 0;
            }

            for (int j = 0; j < n; j++)
            {
                cin >> c;
                if (c == 'X')
                    b[i][j] = 1;
                else
                    b[i][j] = 0;
            }            
        }

        if (same(a, b, n))
            cout << "Pattern " << num << " was preserved.\n";
        else
        {
            rotate(a, t1, n);
            if (same(t1, b, n))
                cout << "Pattern " << num << " was rotated 90 degrees.\n";
            else
            {
                rotate(t1, t2, n);
                if (same(t2, b, n))
                    cout << "Pattern " << num << " was rotated 180 degrees.\n";
                else
                {
                    rotate(t2, t3, n);
                    if (same(t3, b, n))
                        cout << "Pattern " << num << " was rotated 270 degrees.\n";
                    else
                    {
                        reflect(a, t4, n);
                        if (same(t4, b, n))
                            cout << "Pattern " << num << " was reflected vertically.\n";
                        else
                        {
                            rotate(t4, t1, n);
                            if (same(t1, b, n))
                                cout << "Pattern " << num << " was reflected vertically and rotated 90 degrees.\n";
                            else
                            {
                                rotate(t1, t2, n);
                                if (same(t2, b, n))
                                    cout << "Pattern " << num << " was reflected vertically and rotated 180 degrees.\n";
                                else
                                {
                                    rotate(t2, t3, n);
                                    if (same(t3, b, n))
                                        cout << "Pattern " << num << " was reflected vertically and rotated 270 degrees.\n";
                                    else
                                        cout << "Pattern " << num << " was improperly transformed.\n";
                                }
                            }
                        }
                    }
                }
            }
        }

        num++;
    }

    return 0;
}