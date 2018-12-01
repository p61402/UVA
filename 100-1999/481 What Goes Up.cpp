#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    int n, k = 0;
    vector<int> v;

    while (cin >> n)
    {
        v.push_back(n);
        k++;
    }
    vector<int> dp (v.size(), 1);

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[i] < v[j])
            {
                dp[j] = max(dp[i] + 1, dp[j]);
            }
        }
    }

    stack<int> output;
    int maximum = 0, x;
    for (int i = 0; i < dp.size(); i++)
        maximum = max(maximum, dp[i]);
    
    cout << maximum << "\n-\n";
    
    x = maximum;
    for (int i = dp.size() - 1; i >= 0; i--)
    {
        if (dp[i] == x)
        {
            output.push(v[i]);
            x--;
        }
    }

    while (!output.empty())
    {
        cout << output.top() << endl;
        output.pop();
    }
    
    return 0;
}