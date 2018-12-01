#include <iostream>
using namespace std;

struct Maker
{
    string name;
    int low_price;
    int high_price;
};

int main()
{
    int n, num_of_maker, test_case, price, valid_count;
    string maker_name;
    Maker makers[10005];

    cin >> n;

    while (n--)
    {
        cin >> num_of_maker;
        for (int i = 0; i < num_of_maker; i++)
            cin >> makers[i].name >> makers[i].low_price >> makers[i].high_price;

        cin >> test_case;
        for (int i = 0; i < test_case; i++)
        {
            valid_count = 0;
            cin >> price;
            for (int j = 0; j < num_of_maker; j++)
            {
                if (price >= makers[j].low_price && price <= makers[j].high_price)
                {
                    maker_name = makers[j].name;
                    valid_count++;
                }
            }

            if (valid_count == 1)
                cout << maker_name << endl;
            else
                cout << "UNDETERMINED\n";
        }

        if (n)
            cout << endl;
    }
    
    return 0;
}