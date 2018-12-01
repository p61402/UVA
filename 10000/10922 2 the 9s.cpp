#include <iostream>
using namespace std;

int main()
{
    string s;
    int degree, value, temp;

    while (cin >> s && s != "0")
    {
        degree = 1;
        value = 0;
        for (auto c : s)
            value += c - '0';

        while (value / 10 != 0)
        {
            temp = value;
            value = 0;
            while (temp)
            {
                value += temp % 10;
                temp /= 10;
            }
            degree++;
        }

        cout << s;
        if (value % 9 == 0)
            cout << " is a multiple of 9 and has 9-degree " << degree << ".\n";
        else
            cout << " is not a multiple of 9.\n";
    }

    return 0;
}