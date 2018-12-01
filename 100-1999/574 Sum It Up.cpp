#include <iostream>
#include <vector>
using namespace std;

int t, n, a[15];
vector<int> v;
vector<vector<int>> result;

int sum_of_vector(vector<int> v)
{
    int summation = 0;
    for (auto number : v)
        summation += number;
    return summation;
}

bool same(vector<int> v1, vector<int> v2)
{
    if (v1.size() == v2.size())
    {
        for (int i = 0; i < v1.size(); i++)
            if (v1[i] != v2[i])
                return false;
        
        return true;
    }

    return false;
}

void find(int current)
{
    if (current == n)
    {
        if (v.size() && sum_of_vector(v) == t)
        {
            for (auto res : result)
                if (same(v, res))
                    return;

            vector<int> new_v;
            new_v = v;
            result.push_back(v);
        }

        return;
    }
    
    v.push_back(a[current]);
    find(current + 1);
    v.pop_back();
    find(current + 1);
}

int main()
{
    while (cin >> t >> n)
    {
        if (t == 0 && n == 0)
            break;

        for (int i = 0; i < n; i++)
            cin >> a[i];

        v.clear();
        result.clear();
        find(0);

        cout << "Sums of " << t << ":\n";
        if (result.size() == 0)
            cout << "NONE\n";
        else
            for (auto res : result)
            {
                for (int i = 0; i < res.size(); i++)
                {
                    cout << res[i];
                    if (i != res.size() - 1)
                        cout << '+';
                    else
                        cout << endl;
                }
            }
    }

    return 0;
}