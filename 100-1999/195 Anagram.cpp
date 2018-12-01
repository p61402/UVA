#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int upper[26], lower[26];

void generate(string str, int len)
{
    if (str.length() == len)
    {
        cout << str << endl;
        return;
    }

    for (int i = 0; i < 26; i++)
    {
        if (upper[i])
        {
            upper[i]--;
            generate(str + char('A' + i), len);
            upper[i]++;
        }

        if (lower[i])
        {
            lower[i]--;
            generate(str + char('a' + i), len);
            lower[i]++;
        }
    }
}

int main()
{
    int n;
    string s;

    cin >> n;

    while (n--)
    {
        cin >> s;

        memset(upper, 0, sizeof(upper));
        memset(lower, 0, sizeof(lower));

        for (auto c : s)
            if (c >= 'a')
                lower[c - 'a']++;
            else
                upper[c - 'A']++;

        generate("", s.size());
    }

    return 0;
}