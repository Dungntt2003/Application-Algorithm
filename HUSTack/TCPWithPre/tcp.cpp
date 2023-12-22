#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001;
int n, m, cost = 0;
int c[MAXN][MAXN];
int x[MAXN];
bool precedence[MAXN][MAXN] = {false};

void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> c[i][j];

    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        precedence[u][v] = true;
    }
}

int check()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i - 1; j++)
            if (precedence[x[i]][x[j]] == true)
                return cost=-1;
        for (int j = i + 1; j <= n; j++)
            if (precedence[x[j]][x[i]] == true)
                return cost=-1;
        cost += c[x[i]][x[i + 1]];
    }
    cost = cost - c[x[n]][x[n + 1]] + c[x[n]][x[1]];
    return cost;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    check();
    cout << cost << endl;
    return 1;
}
