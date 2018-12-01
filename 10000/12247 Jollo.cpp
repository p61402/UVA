#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    int a[3], b[2], win_count, ans, ans1, ans2, i, j;
    bool win, exist[53];

    while (cin >> a[0] >> a[1] >> a[2] >> b[0] >> b[1] && a[0] != 0)
    {
        sort(a, a + 3);
        sort(b, b + 2);
        memset(exist, false, sizeof(exist));
        exist[a[0]] = exist[a[1]] = exist[a[2]] = exist[b[0]] = exist[b[1]] = true;

        win_count = 0;
        for (i = 0; i < 2; i++)
        {
            win = true;
            for (j = 0; j < 3; j++)
                if (b[i] < a[j])
                    win = false;

            if (win)
                win_count++;
        }

        if (win_count == 2)
        {
            for (i = 1; i <= 52; i++)
                if (!exist[i])
                {
                    ans1 = i;
                    break;
                }
        }
        else if (win_count == 1)
        {
            for (i = a[2] + 1; i <= 52; i++)
                if (!exist[i])
                {
                    ans1 = i;
                    break;
                }

            if (i == 53)
                ans1 = -1;
        }
        else
            ans1 = -1;

        win_count = 0;
        for (i = 0; i < 2; i++)
        {
            win = true;
            for (j = 0; j < 2; j++)
                if (b[i] < a[j])
                    win = false;

            if (win)
                win_count++;
        }

        if (win_count == 2)
        {
            for (i = a[1] + 1; i <= 52; i++)
                if (!exist[i])
                {
                    ans2 = i;
                    break;
                }

            if (i == 53)
                ans2 = -1;
        }
        else
            ans2 = -1;

        if (ans1 == -1 || ans2 == -1)
            ans = max(ans1, ans2);
        else
            ans = min(ans1, ans2);

        cout << ans << endl;
    }

    return 0;
}