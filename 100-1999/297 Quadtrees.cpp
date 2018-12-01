#include <iostream>
#include <cstring>
using namespace std;

bool image[1024];

int backtrack(string s, int i, int depth, int offset)
{
    if (!depth)
        return i;
    
    for (int k = 0; k < 4; k++)
    {
        if (s[i] == 'p')
            i = backtrack(s, i + 1, depth / 4, offset);
        else if (s[i] == 'f')
            for (int j = offset; j < offset + depth; j++)
                image[j] = true;
        i++;
        offset += depth;
    }

    return i - 1;
}

int main()
{
    int n, pixel_count;
    string s1, s2;

    cin >> n;

    while (n--)
    {
        cin >> s1 >> s2;

        pixel_count = 0;
        memset(image, false, sizeof(image));

        backtrack(s1, 0, 1024, 0);

        backtrack(s2, 0, 1024, 0);

        for (int i = 0; i < 1024; i++)
            if (image[i])
                pixel_count++;

        cout << "There are " << pixel_count << " black pixels." << endl;
    }
    
    return 0;
}