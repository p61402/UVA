#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
    int N, D, I, power, value, result;

    cin >> N;

    while (N--)
    {
        cin >> D >> I;

        I--;
        power = pow(2, D - 2);
        value = 0;

        while (I)
        {
            value += (I % 2) * power;
            power /= 2;
            I /= 2;
        }

        result = pow(2, D - 1);
        result += value;

        cout << result << endl;
    }

    cin >> N;
    
    return 0;
}