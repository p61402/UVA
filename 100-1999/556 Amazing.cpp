#include <iostream>
#include <unistd.h>
using namespace std;

int main()
{
    int b, w, sx, sy, cx, cy, m[105][105], c[105][105], add_up[5];
    char ele, dir;

    while(cin >> b >> w)
    {
        if (!b && !w)
            break;

        for (int i = 0; i < b; i++)
            for (int j = 0; j < w; j++)
            {
                cin >> ele;
                m[i][j] = ele - '0';
                c[i][j] = 0;
            }

        for (int i = 0; i < b; i++)
        {
            for (int j = 0; j < w; j++)
                cout << m[i][j];
            cout << endl;
        }

        sx = b - 1;
        sy = 0;
        cx = sx;
        cy = sy;
        dir = 'r';

        while (true)
        {
            if (dir == 'r')
                if ((cx + 1 == b || m[cx + 1][cy]) && (cy + 1 != w && !m[cx][cy + 1]))
                {
                    cy += 1;
                    c[cx][cy] += 1;
                }
                else
                {
                    dir = 'u';
                    continue;
                }
            else if (dir == 'u')
                if ((cy + 1 == w || m[cx][cy + 1]) && (cx - 1 != -1 && !m[cx - 1][cy]))
                {
                    cx -= 1;
                    c[cx][cy] += 1;
                }
                else
                {
                    dir = 'l';
                    continue;
                }
            else if (dir == 'l')
                if ((cx - 1 == -1 || !m[cx - 1][cy]) && (cy - 1 != -1 && !m[cx][cy - 1]))
                {
                    cy -= 1;
                    c[cx][cy] += 1;
                }
                else
                {
                    dir = 'd';
                    continue;
                }
            else
                if ((cy - 1 == -1 || m[cx][cy - 1]) && (cx + 1 != b && !m[cx + 1][cy]))
                {
                    cx += 1;
                    c[cx][cy] += 1;
                }
                else
                {
                    dir = 'r';
                    continue;
                }

            cout << cx << ' ' << cy << endl;
            sleep(1);
            
            if (cx == sx && cy == sy)
                break;
        }

        for (int i = 0; i < 5; i++)
            add_up[i] = 0;

        for (int i = 0; i < b; i++)
            for (int j = 0; j < w; j++)
                add_up[c[i][j]] += 1;

        for (int i = 0; i < 5; i++)
            cout << add_up[i] << ' ';
        cout << endl;
    }

    return 0;
}