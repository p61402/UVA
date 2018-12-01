#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    int n = 1;
    char c1, c2, c3, c4;
    string input;
    map<string, int> dict;

    for (int i = 0; i < 26; i++)
    {
        string s = "";
        dict[s + char('a' + i)] = n++;
    }

    for (int i = 0; i < 26; i++)
    {
        string s = "";
        c1 = char('a' + i);
        for (int j = i + 1; j < 26; j++)
            dict[s + c1 + char('a' + j)] = n++;
    }

    for (int i = 0; i < 26; i++)
    {
        string s = "";
        c1 = char('a' + i);
        for (int j = i + 1; j < 26; j++)
        {
            c2 = char('a' + j);
            for (int k = j + 1; k < 26; k++)
                dict[s + c1 + c2 + char('a' + k)] = n++;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        string s = "";
        c1 = char('a' + i);
        for (int j = i + 1; j < 26; j++)
        {
            c2 = char('a' + j);
            for (int k = j + 1; k < 26; k++)
            {
                c3 = char('a' + k);
                for (int l = k + 1; l < 26; l++)
                    dict[s + c1 + c2 + c3 + char('a' + l)] = n++;
            }
        }
    }

    for (int i = 0; i < 26; i++)
    {
        string s = "";
        c1 = char('a' + i);
        for (int j = i + 1; j < 26; j++)
        {
            c2 = char('a' + j);
            for (int k = j + 1; k < 26; k++)
            {
                c3 = char('a' + k);
                for (int l = k + 1; l < 26; l++)
                {
                    c4 = char('a' + l);
                    for (int m = l + 1; m < 26; m++)
                        dict[s + c1 + c2 + c3 + c4 + char('a' + m)] = n++;
                }
            }
        }
    }


    while (cin >> input)
    {
        cout << dict[input] << endl;
    }

    return 0;
}