#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int n, x_count, max_num, void_count;
    string s;

    while (cin >> n)
    {
        if (!n)
            break;

        vector<int> v;
        max_num = 0;
        void_count = 0;

        getline(cin, s);

        while (n--)
        {
            x_count = 0;

            getline(cin, s);

            for (auto c : s)
                if (c == 'X')
                    x_count++;

            v.push_back(x_count);
            max_num = max(max_num, x_count);
        }

        for (auto e : v)
            void_count += max_num - e;

        cout << void_count << endl;
    }

    return 0;
}