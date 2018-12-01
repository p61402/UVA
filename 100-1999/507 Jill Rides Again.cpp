#include <iostream>
using namespace std;

int main()
{
    int n, num_of_route, route, max_so_far, max_ending_here, start, current_start, end, range;

    cin >> n;

    for (int x = 1; x <= n; x++)
    {
        cin >> num_of_route;

        current_start = 1;
        start = 1;
        end = 1;
        range = 0;
        max_so_far = 0;
        max_ending_here = 0;
        for (int i = 2; i <= num_of_route; i++)
        {
            cin >> route;

            max_ending_here += route;
            if (max_so_far <= max_ending_here)
            {
                if (max_so_far < max_ending_here || (i - current_start) > range)
                {
                    start = current_start;
                    end = i;
                    range = end - start;
                }
                max_so_far = max_ending_here;
            }
            
            if (max_ending_here < 0)
            {
                max_ending_here = 0;
                current_start = i;
            }
        }

        if (max_so_far > 0)
            cout << "The nicest part of route " << x << " is between stops " << start << " and " << end << endl;
        else
            cout << "Route " << x << " has no nice parts\n";
    }
    
    return 0;
}