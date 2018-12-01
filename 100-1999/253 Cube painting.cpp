#include <iostream>
#include <vector>
using namespace std;

vector<char> right_rotate(vector<char> v)
{
    vector<char> new_v (6);
    new_v[0] = v[0];
    new_v[1] = v[2];
    new_v[2] = v[4];
    new_v[3] = v[1];
    new_v[4] = v[3];
    new_v[5] = v[5];

    return new_v;
}

vector<char> down_rotate(vector<char> v)
{
    vector<char> new_v (6);
    new_v[0] = v[4];
    new_v[1] = v[0];
    new_v[2] = v[2];
    new_v[3] = v[3];
    new_v[4] = v[5];
    new_v[5] = v[1];

    return new_v;
}

bool check(vector<char> a, vector<char> b)
{
    for (int i = 0; i < 6; i++)
        if (a[i] != b[i])
            return false;
    return true;
}

bool painting(vector<char> a, vector<char> b, int depth)
{
    if (depth == 8)
        return false;
    
    if (check(a, b))
        return true;
    else
        return painting(right_rotate(a), b, depth + 1) || painting(down_rotate(a), b, depth + 1);
}

int main()
{
    string s;
    vector<char> a (6), b (6);

    while (cin >> s)
    {
        for (int i = 0; i < 6; i++)
            a[i] = s[i];
        
        for (int i = 0; i < 6; i++)
            b[i] = s[i + 6];

        if (painting(a, b, 0))
            cout << "TRUE\n";
        else
            cout << "FALSE\n";
    }
    
    return 0;
}