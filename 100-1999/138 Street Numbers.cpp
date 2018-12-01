#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    long long solution_count = 0, k = 2;

    while (solution_count < 10)
    {
        double n = sqrt((k * k + k) / 2);
        if (floor(n) == n)
        {
            printf("%10lld%10lld\n", (long long) n, k);
            solution_count++;
        }
        k++;
    }

    return 0;
}