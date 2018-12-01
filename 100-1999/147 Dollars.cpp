#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int coins[] = {1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000}, amount_int;
    long long dp[6005];
    double amount;

    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for (int i = 0; i < sizeof(coins) / sizeof(coins[0]); i++)
        for (long long j = coins[i]; j <= 6000; j++)
            dp[j] += dp[j - coins[i]];
        
    while (cin >> amount)
    {
        if (amount == 0)
            break;
        amount_int = amount * 20;
        printf("%6.2f%17lld\n", amount, dp[amount_int]);
    }

    return 0;
}