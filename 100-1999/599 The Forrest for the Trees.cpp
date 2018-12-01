#include <iostream>
#include <cstring>
#include <set>
using namespace std;

int main()
{
    int n, edges[26], v1, v2, num, set_num, acorn_count;
    string input;
    set<int> trees;

    cin >> n;

    while (n--)
    {
        memset(edges, -1, sizeof(edges));
        set_num = 0;
        acorn_count = 0;
        trees.clear();

        while (cin >> input)
        {
            if (input[0] == '*')
                break;
            
            v1 = input[1] - 'A';
            v2 = input[3] - 'A';
            num = edges[v1];

            if (edges[v2] == -1)
                edges[v2] = set_num++;

            if (edges[v1] != -1)
            {
                for (int i = 0; i < 26; i++)
                    if (edges[i] == num)
                        edges[i] = edges[v2];
            }
            else
                edges[v1] = edges[v2];
        }

        cin >> input;

        for (unsigned int i = 0; i < input.size(); i += 2)
            if (edges[input[i] - 'A'] == -1)
                acorn_count++;

        for (int i = 0; i < 26; i++)
            if (edges[i] != -1)
                trees.insert(edges[i]);

        cout << "There are " << trees.size() << " tree(s) and " << acorn_count << " acorn(s)." << endl;
    }

    return 0;
}