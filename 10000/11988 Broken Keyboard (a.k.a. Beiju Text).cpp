#include <iostream>
#include <list>
#include <string>
using namespace std;

int main()
{
    string input;
    list<char> output;
    list<char>::iterator lit;

    while (cin >> input)
    {
        output.clear();
        lit = output.begin();

        for (string::iterator it = input.begin(); it != input.end(); it++)
        {
            if (*it == '[')
                lit = output.begin();
            else if (*it == ']')
                lit = output.end();
            else
                output.insert(lit, *it);
        }

        for (auto v : output)
            cout << v;
        cout << endl;
    }

    return 0;
}