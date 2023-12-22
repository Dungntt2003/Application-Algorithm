#include <bits/stdc++.h>
using namespace std;

int const MAXN = 1e5 + 1;

int n;
int p[MAXN], d[MAXN];
int p_total = 0;
bool t[MAXN] = {false};

void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> d[i] >> p[i];
}

void swap()
{
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (p[i] < p[j])
            {
                int temp = d[i];
                d[i] = d[j];
                d[j] = temp;
                int tmp = p[i];
                p[i] = p[j];
                p[j] = tmp;
            }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    swap();

    int j;
    for (int i = 1; i <= n; i++)
    {
        j = d[i];
        while (j > 0 and t[j] == true)
            j--;
        if (j > 0)
        {
            t[j] = true;
            p_total += p[i];
        }
    }
    cout << p_total;
    return 0;
}
