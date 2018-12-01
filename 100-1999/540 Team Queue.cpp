#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
    int n, a, b, s = 1;
    string command;

    while (cin >> n)
    {
        if (n == 0)
            break;

        int num[1000005] = {0};
        queue<int> team_queue, inner_queue[1005];
        bool team_in_queue[1005] = {false};

        for (int i = 0; i < n; i++)
        {
            cin >> a;
            while (a--)
            {
                cin >> b;
                num[b] = i;
            }
        }

        cout << "Scenario #" << s++ << endl;
        
        while (cin >> command)
        {
            if (command == "ENQUEUE")
            {
                cin >> a;
                
                if (!team_in_queue[num[a]])
                {
                    team_queue.push(num[a]);
                    team_in_queue[num[a]] = true;
                }

                inner_queue[num[a]].push(a);
            }
            else if (command == "DEQUEUE")
            {
                cout << inner_queue[team_queue.front()].front() << endl;

                inner_queue[team_queue.front()].pop();
                
                if (inner_queue[team_queue.front()].empty())
                {
                    team_in_queue[team_queue.front()] = false;
                    team_queue.pop();
                }
            }
            else
                break;
        }

        cout << endl;
    }

    return 0;
}