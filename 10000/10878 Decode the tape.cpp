#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    int n;

    getline(cin, s);
    
    while (getline(cin, s) && s[0] != '_')
    {
        n = 0;
        if (s[1] == 'o')
            n += 128;
        if (s[2] == 'o')
            n += 64;
        if (s[3] == 'o')
            n += 32;
        if (s[4] == 'o')
            n += 16;
        if (s[5] == 'o')
            n += 8;
        if (s[7] == 'o')
            n += 4;
        if (s[8] == 'o')
            n += 2;
        if (s[9] == 'o')
            n += 1;

        cout << char(n);
    }
    
    return 0;
}