#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input;
    int flag = 0;

    while (getline(cin, input))
    {
        for (auto c : input)
            if (c == '"')
            {
                if (flag == 0)
                {
                    flag = 1;
                    cout << "``";
                }
                else
                {
                    flag = 0;
                    cout << "''";
                }
            }
            else
                cout << c;

        cout << endl;
    }

    return 0;
}