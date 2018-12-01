#include <iostream>
#include <string>
#include <cmath>
#include <map>
using namespace std;

int two_complement(int a[])
{
    bool flag = true;
    int i, pos;
    for (i = 31; i >= 0; i--)
        if (flag)
            if (a[i])
                flag = false;
            else
                ;
        else
            if (a[i] == 0)
                a[i] = 1;
            else
                a[i] = 0;
}

int main()
{
    int dec_num, i, ans, power, pos, extended_sign, sign;
    int bin_num[32], converted_bin_num[32];

    while (cin >> dec_num)
    {
        ans = 0;
        power = 1;

        cout << dec_num;

        if (dec_num == -2147483648)
        {
            cout << " converts to " << 128 << endl;
            continue;
        }

        if (dec_num >= 0)
            sign = 0;
        else
            sign = 1;
        dec_num = abs(dec_num);

        for (i = 0; i < 32; i++)
        {
            bin_num[i] = 0;
            converted_bin_num[i] = 0;
        }

        pos = 31;
        while (dec_num)
        {
            bin_num[pos--] = dec_num % 2;
            dec_num /= 2;
        }

        if (sign == 1)
            two_complement(bin_num);

        i = 0;
        for (int m = 24; m >= 0; m -= 8)
            for (int n = 0; n < 8; n++)
                converted_bin_num[i++] = bin_num[m + n];
        
        if (converted_bin_num[0] == 0)
            for (i = 31; i >= 0; i--)
            {
                ans += converted_bin_num[i] * power;
                power *= 2;
            }
        else
        {
            two_complement(converted_bin_num);
            for (i = 31; i >= 0; i--)
            {
                ans += converted_bin_num[i] * power;
                power *= 2;
            }
            ans *= -1;
        }
        
        cout << " converts to " << ans << endl;
    }

    return 0;
}