#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

class Tuple {
public:
    Tuple(int, int, int);
    bool equal(Tuple);
    int a;
    int b;
    int c;
};

Tuple::Tuple(int x, int y, int z)
{
    int arr[3];
    arr[0] = x;
    arr[1] = y;
    arr[2] = z;
    sort(arr, arr + 3);
    a = arr[0];
    b = arr[1];
    c = arr[2];
}

bool Tuple::equal(Tuple another)
{
    return a == another.a && b == another.b && c == another.c;
}

bool exist(vector<Tuple> s, Tuple t)
{
    for (auto x : s)
        if (x.equal(t))
            return true;
    return false;
}

int permutation_count(Tuple t)
{
    if (t.a == t.b && t.b == t.c)
        return 1;
    if (t.a == t.b && t.a != t.c || t.a == t.c && t.a != t.b || t.b == t.c && t.a != t.b)
        return 3;
    if (t.a != t.b && t.b != t.c)
        return 6;
}

int main()
{
    int n, numOfCombinations, numOfPermutations;
    set<int> scores;
    vector<Tuple> tuples;

    for (int i = 0; i <= 20; i++)
    {
        scores.insert(i);
        scores.insert(i * 2);
        scores.insert(i * 3);
    }
    scores.insert(50);

    while (cin >> n && n > 0)
    {
        numOfCombinations = numOfPermutations = 0;
        tuples.clear();

        for (auto i : scores)
            for (auto j : scores)
                for (auto k : scores)
                {
                    if (n - i - j - k == 0)
                    {
                        Tuple t (i, j, k);
                        if (!exist(tuples, t))
                            tuples.push_back(t);
                    }
                }

        numOfCombinations = tuples.size();
        for (auto t : tuples)
            numOfPermutations += permutation_count(t);

        if (tuples.size())
        {
            cout << "NUMBER OF COMBINATIONS THAT SCORES " << n << " IS " << numOfCombinations << ".\n";
            cout << "NUMBER OF PERMUTATIONS THAT SCORES " << n << " IS " << numOfPermutations << ".\n";
        }
        else
            cout << "THE SCORE OF " << n << " CANNOT BE MADE WITH THREE DARTS.\n";

        cout << "**********************************************************************\n";
    }
    
    cout << "END OF OUTPUT\n";

    return 0;
}