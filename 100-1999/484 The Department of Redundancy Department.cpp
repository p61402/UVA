#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    map<int, int> dict;
    vector<int> order;

    while (cin >> n)
    {
        if (find(order.begin(), order.end(), n) != order.end())
            dict[n]++;
        else
        {
            dict[n] = 1;
            order.push_back(n);
        }
    }

    for (auto num : order)
        cout << num << ' ' << dict[num] << endl;

    return 0;
}