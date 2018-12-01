#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int a, b;
    bool valid;
    vector<int> v;

    while (cin >> a >> b)
    {
        if (a != 0 && b != 0 && b != 1 && a >= b)
        {
            v.clear();
            v.push_back(a);
            valid = true;
            while (a != 1)
                if (a % b == 0)
                {
                    a /= b;
                    v.push_back(a);
                }
                else
                {
                    valid = false;
                    break;
                }
        }
        else
            valid = false;

        if (valid)
        {
            for (int i = 0; i < v.size(); i++)
            {
                cout << v[i];

                if (i != v.size() - 1)
                    cout << " ";
                else
                    cout << endl;
            }
        }
        else
            cout << "Boring!\n";    
    }
    
    return 0;
}