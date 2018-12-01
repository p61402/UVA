#include <iostream>
#include <algorithm>
#include <map>
#include <tuple>
using namespace std;

int main()
{
    map<tuple<int, int, int, int, int>, int> courses;
    int n, a[5], most_popular, students;

    while (cin >> n && n)
    {
        courses.clear();
        while (n--)
        {
            cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
            sort(a, a + 5);
            tuple<int, int, int, int, int> t (a[0], a[1], a[2], a[3], a[4]);
            if (courses.find(t) != courses.end())
                courses[t]++;
            else
                courses[t] = 1;
        }

        most_popular = 0;
        for (auto course : courses)
            most_popular = max(most_popular, course.second);

        students = 0;
        for (auto course : courses)
            if (course.second == most_popular)
                students += most_popular;

        cout << students << endl;
    }

    return 0;
}