#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int numOfDigits(int a)
{
    int count_digit = 0;
    while (a)
    {
        a /= 10;
        count_digit++;
    }

    return count_digit;
}

int main()
{
    int n, a, c = 0, summation, sign, integer, numerator, denominator, g, digitOfInteger, digitOfNumerator, digitOfDenominator;

    while (cin >> n && n != 0)
    {
        summation = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            summation += a;
        }

        if (summation >= 0)
            sign = 0;
        else
        {
            sign = 1;
            summation *= -1;
        }

        integer = summation / n;
        numerator = summation % n;
        denominator = n;
        
        g = gcd(denominator, numerator);

        numerator /= g;
        denominator /= g;

        digitOfInteger = numOfDigits(integer);
        digitOfNumerator = numOfDigits(numerator);
        digitOfDenominator = numOfDigits(denominator);
    
        cout << "Case " << ++c << ":\n";

        if (numerator == 0)
        {
            if (sign == 0)
                cout << integer << endl;
            else
                cout << "- " << integer << endl;
        }
        else if (integer == 0)
        {
            if (sign == 0)
            {
                for (int i = 0; i < digitOfDenominator - digitOfNumerator; i++)
                    cout << ' ';
                cout << numerator << endl;

                for (int i = 0; i < digitOfDenominator; i++)
                    cout << '-';
                cout << endl;

                cout << denominator << endl;
            }
            else
            {
                cout << "  ";
                for (int i = 0; i < digitOfDenominator - digitOfNumerator; i++)
                    cout << ' ';
                cout << numerator << endl;
                
                cout << "- ";
                for (int i = 0; i < digitOfDenominator; i++)
                    cout << '-';
                cout << endl;

                cout << "  " << denominator << endl;
            }
        }
        else
        {
            if (sign == 0)
            {
                for (int i = 0; i < digitOfInteger; i++)
                    cout << ' ';
                for (int i = 0; i < digitOfDenominator - digitOfNumerator; i++)
                    cout << ' ';
                cout << numerator << endl;

                cout << integer;
                for (int i = 0; i < digitOfDenominator; i++)
                    cout << '-';
                cout << endl;

                for (int i = 0; i < digitOfInteger; i++)
                    cout << ' ';
                cout << denominator << endl;
            }
            else
            {
                cout << "  ";
                for (int i = 0; i < digitOfInteger; i++)
                    cout << ' ';
                for (int i = 0; i < digitOfDenominator - digitOfNumerator; i++)
                    cout << ' ';
                cout << numerator << endl;

                cout << "- ";
                cout << integer;
                for (int i = 0; i < digitOfDenominator; i++)
                    cout << '-';
                cout << endl;

                cout << "  ";
                for (int i = 0; i < digitOfInteger; i++)
                    cout << ' ';
                cout << denominator << endl;
            }
        }
    }
    
    return 0;
}