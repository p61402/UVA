#include <iostream>
using namespace std;

int main()
{
    int t, n, i, exist[100005], need[100005], result[100005], pos, pass, own, summation;
    bool possible;

    cin >> t;

    for (int x = 1; x <= t; x++)
    {
        cin >> n;

        for (i = 0; i < n; i++)
            cin >> exist[i];
        
        for (i = 0; i < n; i++)
            cin >> need[i];

        summation = 0;
        for (i = 0; i < n; i++)
        {
            result[i] = exist[i] - need[i];
            summation += result[i];
        }

        if (summation >= 0)
        {
            possible = false;

            for (i = 0; i < n; i++)
            {
                if (result[i] < 0)
                    continue;
                pos = i;
                pass = 0;
                own = 0;
                possible = true;
                while (pass != n)
                {
                    if (pos == n)
                        pos = 0;
                    
                    own += result[pos];

                    if (own < 0)
                    {
                        possible = false;
                        break;
                    }

                    pos++;
                    pass++;
                }

                if (possible)
                    break;
            }
        }
        else
            possible = false;

        cout << "Case " << x << ": ";
        if (possible)
            cout << "Possible from station " << i + 1 << endl;
        else
            cout << "Not possible\n";
    }
    
    return 0;
}

                





