#include <bits/stdc++.h>

using namespace std;
int S[9][9];
int x, y;
int res;

int checkValid(int S[][9], int x, int y, int k)
{
    for (int i = 0; i < 9; i++)
    {
        if (S[x][i] == k)
        {
            return 0;
        }
    }
    for (int i = 0; i < 9; i++)
    {
        if (S[i][y] == k)
        {
            return 0;
        }
    }
    int a = x / 3;
    int b = y / 3;
    for (int i = 3 * a; i < 3 * a + 3; i++)
    {
        for (int j = 3 * b; j < 3 * b + 3; j++)
        {
            if (S[i][j] == k)
            {
                return 0;
            }
        }
    }
    return 1;
}

void solve(int S[][9], int x, int y)
{
    if (y == 9)
        if (x == 8)
        {
            res++;
            return;
        }
        else
            solve(S, x + 1, 0);
    else if (S[x][y] == 0)
        for (int k = 1; k <= 9; k++)
        {
            if (checkValid(S, x, y, k))
            {
                S[x][y] = k;
                solve(S, x, y + 1);
                S[x][y] = 0;
            }
        }
    else
        solve(S, x, y + 1);
}

int main()
{
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cin >> S[i][j];
            
    solve(S, 0, 0);
    cout << res;
    return 0;
}
