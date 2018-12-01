#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n, a[105], i = 1;
    bool valid;
    set<int> s;

    while (cin >> n)
    {
        for (int x = 0; x < n; x++)
            cin >> a[x];

        valid = true;
        if (a[0] < 1)
            valid = false;
        for (int x = 1; x < n; x++)
            if (a[x] <= a[x - 1])
                valid = false;

        if (valid)
        {
            s.clear();
            for (int x = 0; x < n; x++)
            {
                for (int y = 0; y <= x; y++)
                    if (s.find(a[x] + a[y]) == s.end())
                        s.insert(a[x] + a[y]);
                    else
                        valid = false;
                
                if (!valid)
                    break;
            }
        }

        cout << "Case #" << i++ << ": ";
        if (valid)
            cout << "It is a B2-Sequence.\n";
        else
            cout << "It is not a B2-Sequence.\n";
        cout << endl;
    }
    
    return 0;
}