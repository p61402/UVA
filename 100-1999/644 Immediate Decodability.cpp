#include <iostream>
#include <string>
using namespace std;

int is_prefix(string s1, string s2)
{
    if (s1.length() == s2.length())
        return !s1.compare(s2);
    else if (s1.length() < s2.length())
        return !s1.compare(s2.substr(0, s1.size()));
    else
        return !s2.compare(s1.substr(0, s2.size()));
}

int main()
{
    string symbols[10], s;
    int n = 0, set_count = 0;
    bool valid;

    while (cin >> s)
    {
        if (s != "9")
            symbols[n++] = s;
        else
        {
            valid = true;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (i != j && is_prefix(symbols[i], symbols[j]))
                        valid = false;
            
            if (valid)
                cout << "Set " << ++set_count << " is immediately decodable\n";
            else
                cout << "Set " << ++set_count << " is not immediately decodable\n";

            n = 0;
        }
    }

    return 0;
}