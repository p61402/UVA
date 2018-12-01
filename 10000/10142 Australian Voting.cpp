#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>
using namespace std;

int main()
{
    int test_case, numberOfCandidates, v, numOfVotes, ballot[25];
    bool eliminated[25];
    vector<int> votes[1005];
    string names[25], vote;

    cin >> test_case;

    while (test_case--)
    {
        cin >> numberOfCandidates;
        cin.ignore();

        for (int i = 0; i < numberOfCandidates; i++)
            getline(cin, names[i]);

        memset(ballot, 0, sizeof(ballot));
        memset(eliminated, false, sizeof(eliminated));
        for (int i = 0; i < sizeof(votes) / sizeof(votes[0]); i++)
            votes[i].clear();
        numOfVotes = 0;

        while (getline(cin, vote) && vote.size() != 0)
        {
            stringstream ss (vote);
            for (int i = 0; i < numberOfCandidates; i++)
            {
                ss >> v;
                votes[numOfVotes].push_back(v);
            }
            numOfVotes++;
        }

        for (int i = 0; i < numOfVotes; i++)
        {
            for (int j = 0; j < numberOfCandidates; j++)
                if (!eliminated[j])
                {
                    ballot[votes[i][0] - 1]++;
                    break;
                }
        }
        for (int i = 0; i < numberOfCandidates; i++)
        {
            cout << names[i] << ' ' << ballot[i] << endl;
        }
    }

    return 0;
}