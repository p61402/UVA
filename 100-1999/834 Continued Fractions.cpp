#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int numerator, denominator, temp;
    vector<int> result;

    while (cin >> numerator >> denominator)
    {
        result.clear();
        while (true)
        {
            result.push_back(numerator / denominator);
            numerator -= result.back() * denominator;
            if (numerator != 1)
            {
                if (numerator == 0)
                    break;
                temp = numerator;
                numerator = denominator;
                denominator = temp;
            }
            else
            {
                result.push_back(denominator);
                break;
            }
            
        }

        cout << "[" << result[0];
        for (int i = 1; i < result.size(); i++)
        {
            if (i == 1)
                cout << ";";
            cout << result[i];
            if (i != result.size() - 1)
                cout << ",";
        }
        cout << "]\n";
    }
    
    return 0;
}