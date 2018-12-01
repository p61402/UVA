#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, x, A, numOfA, possibleA;
    vector<int> v;
    
    while (cin >> n)
    {
        v.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            v.push_back(x);
        }

        sort(v.begin(), v.end());

        if (n % 2 == 1)
        {
            A = v[n / 2];
            numOfA = count(v.begin(), v.end(), A);
            possibleA = 1;
        }
        else
        {
            A = v[n / 2 - 1];
            numOfA = count(v.begin(), v.end(), A);
            if (v[n / 2 - 1] != v[n / 2])
                numOfA += count(v.begin(), v.end(), v[n / 2]);
            possibleA = v[n / 2] - v[n / 2 - 1] + 1;
        }

        cout << A << " " << numOfA << " " << possibleA << endl;
    }

    return 0;
}