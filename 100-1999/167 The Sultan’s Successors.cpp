#include <iostream>
#include <vector>
#include <utility>
#include <cstdio>
using namespace std;

int chessboard[8][8], max_score;
vector<pair<int, int> > queens;

bool safe(int x, int y)
{
    for (auto queen : queens)
        if (queen.first == x || queen.second == y || queen.first - queen.second == x - y || queen.first + queen.second == x + y)
            return false;
    return true;
}

void backtracking(int col)
{
    if (col == 8)
    {
        int score = 0;
        for (auto queen : queens)
            score += chessboard[queen.first][queen.second];

        if (score > max_score)
            max_score = score;
        
        return;
    }

    for (int row = 0; row < 8; row++)
    {
        if (safe(row, col))
        {
            queens.push_back(make_pair(row, col));
            backtracking(col + 1);
            queens.pop_back();
        }
    }

    return;
}

int main()
{
    int n;

    cin >> n;

    while (n--)
    {
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                cin >> chessboard[i][j];

        max_score = 0;

        backtracking(0);

        printf("%5d\n", max_score);
    }

    return 0;
}