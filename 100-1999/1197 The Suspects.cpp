#include <iostream>
#include <vector>
using namespace std;

class Network {
public:
    Network(int size);
    int get(int c) { return connection[c]; }
    int find_root(int c);
    void union_elements(int c1, int c2);
    bool connected(int c1, int c2);
private:
    int connection[30005];
};

Network::Network(int size)
{
    for (unsigned int i = 0; i < size + 1; i++)
        connection[i] = i;
}

int Network::find_root(int c)
{
    while (connection[c] != c)
        c = connection[c];
    return c;
}

void Network::union_elements(int c1, int c2)
{
    connection[find_root(c1)] = connection[find_root(c2)];
}

bool Network::connected(int c1, int c2)
{
    return find_root(c1) == find_root(c2);
}

int main()
{
    int n, m, k, s1, s2, target, suspect_count;

    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
            break;
        
        Network network(n);

        while (m--)
        {
            cin >> k >> s1;
            k--;
            while (k--)
            {
                cin >> s2;
                if (s1 != s2)
                    network.union_elements(s1, s2);
            }      
        }

        target = network.find_root(0);
        suspect_count = 0;
        for (int i = 0; i < n; i++)
        {
            if (network.find_root(i) == target)
                suspect_count++;
        }
        
        cout << suspect_count << endl;
    }
    
    return 0;
}