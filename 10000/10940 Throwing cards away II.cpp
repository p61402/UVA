#include <iostream>
#include <deque>
using namespace std;

void build_table(int t[])
{
    t[1] = 1;
    int index = 2, flag = 2, counting = 1;

    while (counting <= 19)
    {
        for (int i = 2; i <= flag; i += 2)
            t[index++] = i;
        
        flag *= 2;
        counting++;
    }
}

int main()
{
    int n, table[530000];

    build_table(table);

    while (cin >> n && n != 0)
        cout << table[n] << endl;

    return 0;
}