#include <iostream>
#include <set>
#include <string>
#include <cctype>
#include <sstream>
using namespace std;

int main()
{
    set<string> dict;
    string input, token, uncomplete_word = "";
    bool uncompleted = false;

    while (cin >> input)
    {
        if (input.back() == '-')
        {
            uncomplete_word += input.substr(0, input.size() - 1);
            uncompleted = true;
            continue;
        }

        if (uncompleted)
        {
            uncomplete_word += input;
            input = uncomplete_word;
            uncompleted = false;
            uncomplete_word = "";
        }

        for (unsigned int i = 0; i < input.size(); i++)
            if (isalpha(input[i]) || input[i] == '-')
                input[i] = tolower(input[i]);
            else
                input[i] = ' ';

        istringstream ss (input);
        while (getline(ss, token, ' '))
            if (token != "")
                dict.insert(token);
    }

    for (auto word : dict)
        cout << word << endl;

    return 0;
}