#include <iostream>
#include <map>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
    string s;
    int n, numberOfSpecies;
    map<string, int> species;

    cin >> n;

    getline(cin, s);
    getline(cin, s);

    while (n--)
    {
        species.clear();
        numberOfSpecies = 0;
        while (getline(cin, s) && s.length())
        {
            if (species.find(s) != species.end())
                species[s]++;
            else
                species[s] = 1;
            numberOfSpecies++;
        }

        for (map<string, int>::iterator it = species.begin(); it != species.end(); it++)
        {
            cout << it->first;
            printf(" %.4f\n", (double)it->second * 100 / numberOfSpecies);
        }

        if (n)
            cout << endl;
    }

    return 0;
}