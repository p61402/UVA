#include <iostream>
#include <string>
using namespace std;

bool isLeap(int y)
{
    return (y % 4 == 0 && y % 100 != 0 || y % 400 == 0);
}

string zodiac_sign(int m, int d)
{
    if (m == 1 && d >= 21 || m == 2 && d <= 19)
        return "aquarius";
    else if (m == 2 && d >= 20 || m == 3 && d <= 20)
        return "pisces";
    else if (m == 3 && d >= 21 || m == 4 && d <= 20)
        return "aries";
    else if (m == 4 && d >= 21 || m == 5 && d <= 21)
        return "taurus";
    else if (m == 5 && d >= 22 || m == 6 && d <= 21)
        return "gemini";
    else if (m == 6 && d >= 22 || m == 7 && d <= 22)
        return "cancer";
    else if (m == 7 && d >= 23 || m == 8 && d <= 21)
        return "leo";
    else if (m == 8 && d >= 22 || m == 9 && d <= 23)
        return "virgo";
    else if (m == 9 && d >= 24 || m == 10 && d <= 23)
        return "libra";
    else if (m == 10 && d >= 24 || m == 11 && d <= 22)
        return "scorpio";
    else if (m == 11 && d >= 23 || m == 12 && d <= 22)
        return "sagittarius";
    else if (m == 12 && d >= 23 || m == 1 && d <= 20)
        return "capricorn";
}

int main()
{
    int dayOfMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int t, y, m, d, period, i, j;
    string s;

    cin >> t;

    for (i = 1; i <= t; i++)
    {
        cin >> s;

        m = (s[0] - '0') * 10 + (s[1] - '0');
        d = (s[2] - '0') * 10 + (s[3] - '0');
        y = (s[4] - '0') * 1000 + (s[5] - '0') * 100 + (s[6] - '0') * 10 + (s[7] - '0');

        period = 280;

        if (isLeap(y))
            dayOfMonth[2] = 29;
        else
            dayOfMonth[2] = 28;

        period -= dayOfMonth[m] - d;
        d = dayOfMonth[m];

        if (m != 12)
        {
            for (j = m + 1; j <= 12; j++)
            {
                period -= dayOfMonth[j];

                if (period <= 0)
                {
                    d = period + dayOfMonth[j];
                    period = 0;
                    break;
                }
            }

            if (j == 13)
                m = 12;
            else
                m = j;
        }
        
        if (m == 12 && period)
        {
            y++;
            if (isLeap(y))
                dayOfMonth[2] = 29;
            else
                dayOfMonth[2] = 28;
        }

        if (period)
        {
            for (j = 1; j <= 12; j++)
            {
                period -= dayOfMonth[j];
                
                if (period <= 0)
                {
                    d = period + dayOfMonth[j];
                    period = 0;
                    break;
                }
            }

            if (j == 13)
                m = 12;
            else
                m = j;
        }

        cout << i << ' ';
        if (m < 10)
            cout << '0';
        cout << m << '/';
        if (d < 10)
            cout << '0';
        cout << d << '/' << y << ' ' << zodiac_sign(m, d) << endl;
    }

    return 0;
}