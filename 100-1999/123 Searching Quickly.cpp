#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cctype>
using namespace std;

int main()
{
    set<string> ignore_words;
    vector<string> v[205];
    vector<string> keywords;
    map<string, vector<int> > dict;
    string s, token;
    int i = 0;

    while (true)
    {
        cin >> s;
        if (s != "::")
            ignore_words.insert(s);
        else
            break;
    }

    getchar();
    while (getline(cin, s))
    {
        istringstream ss(s);
        
        while (getline(ss, token, ' '))
        {
            for (unsigned int k = 0; k < token.size(); k++)
                token[k] = tolower(token[k]);
            v[i].push_back(token);
            set<string>::iterator it = find(ignore_words.begin(), ignore_words.end(), token);
            if (it == ignore_words.end())
            {
                vector<int>::iterator it1 = find(dict[token].begin(), dict[token].end(), i);
                if (it1 == dict[token].end())
                    dict[token].push_back(i);
                vector<string>::iterator it2 = find(keywords.begin(), keywords.end(), token);
                if (it2 == keywords.end())
                    keywords.push_back(token);
            }
        }
        i++;
    }

    sort(keywords.begin(), keywords.end());

    for (auto keyword : keywords)
    {
        for (auto num : dict[keyword])
        {
            for (int j = 0; j < v[num].size(); j++)
            {
                if (v[num][j].compare(keyword) == 0)
                {
                    if (j != 0)
                        cout << v[num][0];
                    else
                        for (unsigned int l = 0; l < v[num][0].size(); l++)
                            cout << char(toupper(v[num][0][l]));
                    for (int k = 1; k < v[num].size(); k++)
                    {
                        cout << ' ';
                        if (k != j)
                            cout << v[num][k];
                        else
                            for (unsigned int l = 0; l < v[num][k].size(); l++)
                                cout << char(toupper(v[num][k][l]));
                    }
                    cout << endl;
                }
            }
        }
    }

    return 0;
}