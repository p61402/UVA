#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <cstring>
using namespace std;

int n, t, tracks[25], diff, best_fit = 0;
bool usage[25];
vector<int> ans;

void find_answer(int summation, int current)
{
    if (current == t)
    {
        if (summation <= n && abs(summation - n) < diff)
        {
            ans.clear();
            for (int i = 0; i < t; i++)
                if (usage[i])
                    ans.push_back(tracks[i]);
            diff = abs(summation - n);
            best_fit = summation;
        }

        return;
    }

    usage[current] = true;
    find_answer(summation + tracks[current], current + 1);

    usage[current] = false;
    find_answer(summation, current + 1);
}

int main()
{
    while (cin >> n >> t)
    {
        for (int i = 0; i < t; i++)
            cin >> tracks[i];

        diff = INT_MAX;
        memset(usage, false, sizeof(usage));

        find_answer(0, 0);

        for (auto a : ans)
            cout << a << ' ';
        cout << "sum:" << best_fit << endl;
    }

    return 0;
}