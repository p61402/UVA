#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Network {
public:
    Network(int size);
    int find_root(int c);
    void union_computers(int c1, int c2);
    bool connected(int c1, int c2);
private:
    vector<int> connection;
};

Network::Network(int size)
{
    int buffer = 5;
    connection.resize(size + buffer);
    for (unsigned int i = 0; i < connection.size(); i++)
        connection[i] = i;
}

int Network::find_root(int c)
{
    while (connection[c] != c)
        c = connection[c];
    return c;
}

void Network::union_computers(int c1, int c2)
{
    connection[find_root(c1)] = connection[find_root(c2)];
}

bool Network::connected(int c1, int c2)
{
    return find_root(c1) == find_root(c2);
}

int main()
{
    int n, num_of_computer, c1, c2, success_ans_count, unsuccess_ans_count;
    string query, query_type;

    cin >> n;

    while (n--)
    {
        cin >> num_of_computer;
        cin.ignore();

        Network network(num_of_computer);
        success_ans_count = 0;
        unsuccess_ans_count = 0;

        while (getline(cin, query) && query.size())
        {
            istringstream ss(query);
            ss >> query_type >> c1 >> c2;
            if (query_type == "c")
                network.union_computers(c1, c2);
            else if (query_type == "q")
            {
                if (network.connected(c1, c2))
                    success_ans_count++;
                else
                    unsuccess_ans_count++;
            }
        }

        cout << success_ans_count << ',' << unsuccess_ans_count << endl;

        if (n)
            cout << endl;
    }
    
    return 0;
}