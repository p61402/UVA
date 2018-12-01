#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, a, b, numOfNodes;

    while (cin >> n)
    {
        vector<vector<int>> connect (n + 1);
        vector<int> neighbors (n + 1);
        
        for (int i = 0; i < n; i++)
        {
            cin >> a >> b;

            connect[a].push_back(b);
            connect[b].push_back(a);

            neighbors[a]++;
            neighbors[b]++;
        }

        numOfNodes = 1;
        

        cin >> n;

        if (n == -1)
            break;
    }
}