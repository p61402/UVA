#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    int n, k, num, curr;

    while (cin >> n)
    {
        if (n == 0)
            break;

        while (cin >> k)
        {
            if (k == 0)
                break;

            stack<int> s;
            vector<int> v;

            v.push_back(k);
            for (int i = 1; i < n; i++)
            {
                cin >> k;
                v.push_back(k);
            }

            num = 1;
            curr = 0;

            while (num <= n)
            {
                while (s.empty() || s.top() != v[curr])
                {
                    s.push(num);
                    num++;
                    if (num > n)
                        break;
                }

                while (!s.empty() && s.top() == v[curr])
                {
                    s.pop();
                    curr++;
                }
            }

            if (curr == n)
                cout << "Yes\n";
            else
                cout << "No\n";
        }

        cout << endl;
    }

    return 0;
}