#include <iostream>
using namespace std;

int main()
{
    long long s, d, summation, i;

    while (cin >> s >> d)
    {
        summation = 0;
        i = s;

        while (d > summation)
        {
            summation += i;
            i++;
        }

        cout << i - 1 << endl;
    }
    
    return 0;
}