#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n, m, start, end, interval;
    bool timeline[1000005], valid;

    while (cin >> n >> m && n != 0 || m != 0)
    {
        valid = true;
        memset(timeline, false, sizeof(timeline));

        while (n--)
        {
            cin >> start >> end;

            if (!valid)
                continue;

            for (int i = start + 1; i <= end; i++)
            {
                if (timeline[i])
                {
                    valid = false;
                    break;
                }
                else
                    timeline[i] = true;
            }
        }

        while (m--)
        {
            cin >> start >> end >> interval;
            
            if (!valid)
                continue;

            while (start <= 1000000)
            {
                for (int i = start + 1; i <= end; i++)
                {
                    if (i > 1000000)
                    {
                        start = 1000001;
                        break;
                    }

                    if (timeline[i])
                    {
                        valid = false;
                        break;
                    }
                    else
                        timeline[i] = true;
                }

                start += interval;
                end += interval;
            }
        }

        if (valid)
            cout << "NO CONFLICT\n";
        else
            cout << "CONFLICT\n";
    }

    return 0;
}