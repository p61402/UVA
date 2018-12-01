#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

struct cell {
    int x;
    int y;
};

int main()
{
    int n, step, min_step, max_step;
    char p;
    cell c;
    vector<cell> one, three;

    while (cin >> n)
    {
        one.clear();
        three.clear();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                cin >> p;
                c.x = i;
                c.y = j;
                if (p - '0' == 1)
                    one.push_back(c);
                else if (p - '0' == 3)
                    three.push_back(c);
            }

        max_step = 0;
        for (auto a : one)
        {
            min_step = INT_MAX;
            for (auto b : three)
            {
                step = abs(a.x - b.x) + abs(a.y - b.y);
                if (step < min_step)
                    min_step = step;
            }

            if (min_step > max_step)
                max_step = min_step;
        }
        
        cout << max_step << endl;
    }

    return 0;
}