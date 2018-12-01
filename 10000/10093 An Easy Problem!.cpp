#include <iostream>
using namespace std;

int main()
{
    string s;
    int summation, i, base;

    while (cin >> s)
    {
        summation = 0;
        base = int('1');
        for (auto c : s)
        {
            if (int(c) >= '0' && int(c) > base)
                base = int(c);
            
            if (c >= '0' && c <= '9')
                summation += c - '0';
            else if (c >= 'A' && c <= 'Z')
                summation += c - 'A' + 10;
            else if (c >= 'a' && c <= 'z')
                summation += c - 'a' + 36;
        }

        if (base >= '0' && base <= '9')
            base -= '0';
        else if (base >= 'A' && base <= 'Z')
            base = base - 'A' + 10;
        else if (base >= 'a' && base <= 'z')
            base = base - 'a' + 36;

        for (i = base; i < 62; i++)
            if (summation % i == 0)
                break;

        if (i < 62)
            cout << i + 1 << endl;
        else
            cout << "such number is impossible!\n";
    }

    return 0;
}