#include <iostream>
using namespace std;

int main()
{
    int r, c, t = 0, mine_count;
    char field[105][105];
    bool first = true;

    while (cin >> r >> c && r > 0 && c > 0)
    {
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                cin >> field[i][j];

        if (!first)
            cout << endl;
        else
            first = false;
        
        cout << "Field #" << ++t << ":\n";

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (field[i][j] == '*')
                    cout << '*';
                else
                {
                    mine_count = 0;
                    if (i - 1 >= 0 && field[i - 1][j] == '*')
                        mine_count++;
                    if (j - 1 >= 0 && field[i][j - 1] == '*')
                        mine_count++;
                    if (i + 1 < r && field[i + 1][j] == '*')
                        mine_count++;
                    if (j + 1 < c && field[i][j + 1] == '*')
                        mine_count++;
                    if (i - 1 >= 0 && j - 1 >= 0 && field[i - 1][j - 1] == '*')
                        mine_count++;
                    if (i - 1 >= 0 && j + 1 < c && field[i - 1][j + 1] == '*')
                        mine_count++;
                    if (i + 1 < r && j - 1 >= 0 && field[i + 1][j - 1] == '*')
                        mine_count++;
                    if (i + 1 < r && j + 1 < c && field[i + 1][j + 1] == '*')
                        mine_count++;
                    cout << mine_count;
                }
            }
            cout << endl;
        }
    }
    
    return 0;
}