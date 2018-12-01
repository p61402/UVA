#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    map<char, char> table = {{'A', 'A'}, {'E', '3'}, {'H', 'H'}, {'I', 'I'}, 
    {'J', 'L'}, {'L', 'J'}, {'M', 'M'}, {'O', 'O'}, {'S', '2'}, {'T', 'T'},
    {'U', 'U'}, {'V', 'V'}, {'W', 'W'}, {'X', 'X'}, {'Y', 'Y'}, {'Z', '5'},
    {'1', '1'}, {'2', 'S'}, {'3', 'E'}, {'5', 'Z'}, {'8', '8'}};
    string s1, s2;
    bool isPalindrome, isMirror;

    while (cin >> s1)
    {
        s2 = s1;
        reverse(s2.begin(), s2.end());

        if (s1.compare(s2) == 0)
            isPalindrome = true;
        else
            isPalindrome = false;

        for (int i = 0; i < s2.length(); i++)
            if (table.find(s2[i]) != table.end())
                s2[i] = table[s2[i]];
            else
                s2[i] = '.';

        if (s1.compare(s2) == 0)
            isMirror = true;
        else
            isMirror = false;

        cout << s1 << " -- ";
        if (isPalindrome && isMirror)
            cout << "is a mirrored palindrome.\n";
        else if (isPalindrome)
            cout << "is a regular palindrome.\n";
        else if (isMirror)
            cout << "is a mirrored string.\n";
        else
            cout << "is not a palindrome.\n";
        cout << endl;
    }
    
    return 0;
}