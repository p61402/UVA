#include <iostream>
using namespace std;

int main()
{
    long long n;

    while (cin >> n)
    {
        n = (((1 + n) * (1 + n)) / 4) * 2 - 1;
        cout << 3 * n - 6 << endl;
    }

    return 0;
}