#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n, m, coin[105], summation, avg;

    cin >> n;

    while (n--)
    {
        summation = 0;
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> coin[i];
            summation += coin[i];
        }

        avg = summation / 2;

        vector<int> dp (avg + 1, 0);

        for (int i = 0; i < m; i++)
            for (int j = avg; j - coin[i] >= 0; j--)
                dp[j] = max(dp[j], dp[j - coin[i]] + coin[i]);

        cout << summation - 2 * dp[avg] << endl;
    }
    
    return 0;
}