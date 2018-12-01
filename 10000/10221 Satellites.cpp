#include <iostream>
#include <cstdio>
#include <cmath>
#define pi 3.14159265359
using namespace std;

int main()
{
    int s;
    string type;
    double a, degree, distance, chord;

    while (cin >> s >> a >> type)
    {
        s += 6440;
        
        if (a > 180)
            a = 360 - a;
        
        if (type == "deg")
            degree = a;
        else if (type == "min")
            degree = a / 60;
        
        distance = 2 * pi * s * degree / 360;
        chord = sqrt(2 * s * s * (1 - cos(degree * pi / 180)));

        printf("%.6f %.6f\n", distance, chord);
    }

    return 0;
}