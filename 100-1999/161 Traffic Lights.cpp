#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    int x, i = 0, k, hour, minute, second, start = 100;
    bool t[105][18005], result, found;
    string s;

    while (getline(cin, s))
    {
        if (s == "0 0 0")
            break;
        stringstream ss(s);
        while (ss >> x)
        {
            if (x == 0)
                break;

            if (x < start)
                start = x;

            for (int m = 1; m < x - 5; m++)
                t[i][m] = true;
            k = 1;
            while (2 * k * x <= 18000)
            {
                for (int m = 2 * k * x; m < (2 * k + 1) * x - 5; m++)
                    if (m <= 18000)
                        t[i][m] = true;
                    else
                        break;
                k++;
            }
            i++;
        }

        if (x == 0)
        {
            found = false;
            for (int m = 2 * start; m <= 18000; m++)
            {
                result = true;
                for (int n = 0; n < i; n++)
                    result = result && t[n][m];

                if (result)
                {
                    int timing = m;
                    hour = timing / 3600;
                    timing %= 3600;
                    minute = timing / 60;
                    second = timing % 60;
                    cout << '0' << hour << ':';
                    if (minute >= 10)
                        cout << minute;
                    else
                        cout << '0' << minute;
                    cout << ':';
                    if (second >= 10)
                        cout << second;
                    else
                        cout << '0' << second;
                    cout << endl;
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Signals fail to synchronise in 5 hours\n";
            i = 0;
            start = 100;
            memset(t, false, sizeof(t[0][0]) * 105 * 18005);
        }
    }

    return 0;
}