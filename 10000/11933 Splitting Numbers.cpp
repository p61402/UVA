#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
    int n, i, digit_count, p, ans1, ans2;
    bool digits[32], a[32], b[32];

    while (cin >> n && n != 0)
    {
        memset(digits, false, sizeof(digits));
        memset(a, false, sizeof(a));
        memset(b, false, sizeof(b));

        i = 0;
        while (n)
        {
            digits[i++] = bool(n % 2);
            n /= 2;
        }

        digit_count = 0;
        for (int k = 0; k < 32; k++)
            if (digits[k])
                if (++digit_count % 2 == 1)
                    a[k] = true;
                else
                    b[k] = true;

        p = 1;
        ans1 = ans2 = 0;
        for (int k = 0; k < 32; k++)
        {
            ans1 += a[k] * p;
            ans2 += b[k] * p;
            p *= 2;
        }

        cout << ans1 << ' ' << ans2 << endl;
    }

    return 0;
}