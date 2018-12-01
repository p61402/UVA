#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int string2int(string s)
{
    int num = 0, power = 1;

    if (s.length() < 5)
        for (int i = s.length() - 1; i >= 0; i--, power *= 32)
            num += (s[i] - 'a' + 1) * power;
    else
        for (int i = 4; i >= 0; i--, power *= 32)
            num += (s[i] - 'a' + 1) * power;

    return num;
}

int main()
{
    string input, word;
    int C, len;
    vector<int> v;
    bool valid = false;

    while (getline(cin, input))
    {
        v.clear();
        
        istringstream ss (input);

        while (ss >> word)
            v.push_back(string2int(word));

        sort(v.begin(), v.end());

        C = 1;
        len = v.size();
        valid = false;
        while (!valid)
        {
            valid = true;
            for (int x = 0; x < len - 1; x++)
                for (int y = x + 1; y < len; y++)
                    if ((C / v[x]) % len == (C / v[y]) % len)
                    {
                        C = min((C / v[x] + 1) * v[x], (C / v[y] + 1) * v[y]);
                        valid = false;
                        break;
                    }
        }

        cout << input << endl << C << endl << endl;
    }
    
    return 0;
}