#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

struct Register
{
    int num;
    int period;
    int next_time;
};

struct compare
{
    bool operator()(const Register& r1, const Register& r2) const
    {
        if (r1.next_time > r2.next_time)
            return true;
        else if (r1.next_time == r2.next_time)
            return r1.num >  r2.num;
        else
            return false;
    }
};

int main()
{
    priority_queue<Register, vector<Register>, compare> pq;
    string s;
    int register_num, register_period, instruction_count;

    while (cin >> s)
    {
        if (s == "#")
            break;

        cin >> register_num >> register_period;

        Register r = { register_num, register_period, register_period };
        pq.push(r);
    }

    cin >> instruction_count;

    for (int i = 0; i < instruction_count; i++)
    {
        Register r = { pq.top().num, pq.top().period, pq.top().next_time + pq.top().period };
        cout << r.num << endl;
        pq.pop();
        pq.push(r);
    }

    return 0;
}