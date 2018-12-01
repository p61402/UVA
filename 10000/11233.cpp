#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    int L, N;
    string s1, s2, s;
    map<string, string> irregular_words;
    map<string, string>::iterator iter;

    cin >> L >> N;

    while (L--)
    {
        cin >> s1 >> s2;
        irregular_words[s1] = s2;
    }

    while (N--)
    {
        cin >> s;
        iter = irregular_words.find(s);

        char last = s.at(s.size() - 1);
        char second_last = s.at(s.size() - 2);
        string last_two = s.substr(s.size() - 2, 2);

        if (iter != irregular_words.end())
            cout << iter->second << endl;
        else if (last == 'y' && second_last != 'a' && second_last != 'e' && second_last != 'i' && second_last != 'o' && second_last != 'u')
            cout << s.substr(0, s.size() - 1) << "ies" << endl;
        else if (last == 'o' || last == 's' || last == 'x' || last_two == "ch" || last_two == "sh")
            cout << s << "es" << endl;
        else
            cout << s << 's' << endl;
    }

    return 0;
}