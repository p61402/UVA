#include <iostream>
using namespace std;

int main()
{
    int n, x, y, pages;

    while (cin >> n && n)
    {
        if (n % 4 == 0)
            pages = n / 4;
        else
            pages = n / 4 + 1;
        
        x = 1;
        y = pages * 4;

        cout << "Printing order for " << n << " pages:\n";

        if (n == 1)
        {
            cout << "Sheet 1, front: Blank, 1\n";
            continue;
        }

        for (int i = 1; i <= pages; i++)
        {
            cout << "Sheet " << i << ", front: ";
            if (y <= n)
                cout << y << ", ";
            else
                cout << "Blank, ";
            cout << x << endl;

            cout << "Sheet " << i << ", back : ";
            cout << x + 1 << ", ";
            if (y - 1 <= n)
                cout << y - 1 << endl;
            else
                cout << "Blank" << endl;

            x += 2;
            y -= 2;
        }
    }

    return 0;
}