#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int K, n;
    string s;
    vector<string> original, result, move;

    cin >> K;

    while (K--)
    {
        cin >> n;
        cin.ignore();

        original.clear();
        result.clear();
        move.clear();

        for (int i = 0; i < n; i++)
        {
            getline(cin, s);
            original.push_back(s);
        }

        for (int i = 0; i < n; i++)
        {
            getline(cin, s);
            result.push_back(s);
        }

        int i = original.size() - 1, j = i;

        while (i >= 0 && j >= 0)
        {
            if (original[i] == result[j])
                j--;
            i--;
        }

        for (int x = j; x >= 0; x--)
            cout << result[x] << endl;
        cout << endl;
    }
    
    return 0;
}