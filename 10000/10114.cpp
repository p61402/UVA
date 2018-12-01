#include <iostream>
#include <vector>
#include <iterator>
#include <utility>
using namespace std;

int main()
{
    int month, number_of_depreciation_record, m;
    double down_payment, loan, car_value, d, depreciation_rate[101], each_pay;

    while (cin >> month >> down_payment >> loan >> number_of_depreciation_record)
    {
        if (month < 0)
            break;

        for (int i = 0; i < 101; i++)
            depreciation_rate[i] = 0;

        while (number_of_depreciation_record--)
        {
            cin >> m >> d;
            depreciation_rate[m] = 1 - d;
        }

        for (int i = 1; i < 101; i++)
            if (depreciation_rate[i] == 0)
                depreciation_rate[i] = depreciation_rate[i - 1];

        car_value = (down_payment + loan) * depreciation_rate[0];
        each_pay = loan / month;

        if (car_value > loan)
        {
            cout << "0 months\n";
            continue;
        }
        
        for (int i = 1; i <= month; i++)
        {
            car_value *= depreciation_rate[i];
            loan -= each_pay;

            if (car_value > loan)
            {
                cout << i;
                if (i == 1)
                    cout << " month\n";
                else
                    cout << " months\n";
                
                break;
            }
        }
    }

    return 0;
}