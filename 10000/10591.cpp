#include <iostream>
#include <cmath>
using namespace std;

bool happy(int n)
{
    int a[1000] = {false}, sum;

    while (n != 1)
    {
        sum = 0;

        while (n)
        {
            sum += pow(n % 10, 2);
            n /= 10;
        }

        n = sum;

        if (a[n])
            break;
        else
            a[n] = true;
    }

    if (n == 1)
        return true;
    else
        return false;
}

int main()
{
    int p, n;

    cin >> p;

    for (int i = 1; i <= p; i++)
    {
        cin >> n;
        if (happy(n))
            cout << "Case #" << i << ": " << n << " is a Happy number.\n";
        else
            cout << "Case #" << i << ": " << n << " is an Unhappy number.\n";
    }

    return 0;
}