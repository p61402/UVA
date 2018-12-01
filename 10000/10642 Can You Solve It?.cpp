#include <iostream>
using namespace std;

int main()
{
    long long n, x1, y1, x2, y2;

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << "Case " << i << ": " << y1 + x2 + (x1 + y1 + x2 + y2 + 2) * (x2 + y2 - x1 - y1 - 1) / 2 + 1 << endl;
    }

    return 0;
}