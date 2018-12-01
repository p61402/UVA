#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int x)
{
    if (x % 2 == 0)
        return true;
    
    for (int i = 3; i <= int(sqrt(x)); i++)
        if (x % i == 0)
            return false;

    return true;
}

/* Iterative Function to calculate (x^y)%p in O(log y) */
long long power(long long x, long long y, long long p)
{
    long long res = 1;      // Initialize result
 
    x = x % p;  // Update x if it is more than or 
                // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }

    return res;
}

int main()
{
    int n;
    bool isCarmichael;

    while (cin >> n)
    {
        if (!n)
            break;

        if (!isPrime(n))
        {
            isCarmichael = true;

            for (unsigned int i = 2; i < n; i++)
                if (power(i, n, n) != i)
                {
                    isCarmichael = false;
                    break;
                }            
        }
        else
            isCarmichael = false;

        if (isCarmichael)
            cout << "The number " << n << " is a Carmichael number.\n";
        else
            cout << n << " is normal.\n";
    }

    return 0;
}