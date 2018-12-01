#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string s1, s2;

    while (getline(cin, s1) && s1 != "DONE")
    {
        s2 = "";
        for (auto c : s1)
            if (!ispunct(c) && c != ' ')
                s2 += tolower(c);

        s1 = s2;

        reverse(s2.begin(), s2.end());

        if (s1.compare(s2) == 0)
            cout << "You won't be eaten!\n";
        else
            cout << "Uh oh..\n";
    }

    return 0;
}