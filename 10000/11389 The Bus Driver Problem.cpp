#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
    int n, d, r, morning[105], evening[105], work_time, overtime_amount;

    while (cin >> n >> d >> r)
    {
        if (n == 0 && d == 0 && r == 0)
            break;

        for (int i = 0; i < n; i++)
            cin >> morning[i];
        
        for (int i = 0; i < n; i++)
            cin >> evening[i];

        sort(morning, morning + n);
        sort(evening, evening + n, greater<int>());

        overtime_amount = 0;

        for (int i = 0; i < n; i++)
        {
            work_time = morning[i] + evening[i];
            if (work_time > d)
                overtime_amount += (work_time - d) * r;
        }

        cout << overtime_amount << endl;
    }

    return 0;
}