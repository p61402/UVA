#include <iostream>
#include <string>
#include <cstring>
using namespace std;

bool ans[10000000] = {false};

int main()
{
    int test_case = 0, num, i, len, visit_count;
    bool valid, found, occurrence[10], visited[10];
    string s;

    for (int x = 10; x <= 9999999; x++)
    {
        valid = true;
        memset(occurrence, false, sizeof(occurrence));
        s = to_string(x);
        for (auto c : s)
            if (occurrence[c - '0'])
                valid = false;
            else
                occurrence[c - '0'] = true;
        
        if (valid)
        {
            i = 0;
            len = s.size();
            visit_count = 0;
            memset(visited, false, sizeof(visited));

            while (visit_count < len)
            {
                i = ((s[i] - '0') + i) % len;
                if (visited[i])
                    break;
                else
                {
                    visited[i] = true;
                    visit_count++;
                }
            }

            if (visit_count == len)
                ans[x] = true;
        }
    }
    
    while (cin >> num)
    {
        if (num == 0)
            break;

        test_case++;
        
        while (!ans[num])
            num++;
        cout << "Case " << test_case << ": " << num << endl;
    }
    
    return 0;
}