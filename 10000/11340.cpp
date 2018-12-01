#include <iostream>
#include <string>
#include <map>
#include <iomanip>
using namespace std;

int main()
{
    int n, k, m;
    double cost, total_cost;
    char ch;
    string line;
    map<char, double> dict;
    map<char, double>::iterator it;

    cin >> n;

    while (n--)
    {
        cin >> k;

        dict.clear();

        while (k--)
        {
            cin >> ch >> cost;

            dict[ch] = cost * 0.01;
        }

        cin >> m;
        getline(cin, line);

        total_cost = 0;

        while (m--)
        {
            getline(cin, line);

            for (auto &c : line)
            {
                it = dict.find(c);
                if (it != dict.end())
                    total_cost += it->second;
            }
        }

        cout << setiosflags(ios::fixed|ios::showpoint) << setprecision(2) << total_cost << '$' << endl;
    }

    return 0;
}