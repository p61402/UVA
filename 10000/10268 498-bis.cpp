#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    long long x, n, t, v, p;
    vector<int> a;
    string s;

    while (cin >> x)
    {
        cin.ignore();
        getline(cin, s);
        stringstream ss (s);

        a.clear();
        while (ss >> t)
            a.push_back(t);

        n = a.size();
        v = 0;
        p = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            v += a[i] * (n - i - 1) * p;
            p *= x;
        }

        cout << v << endl;
    }

    return 0;
}