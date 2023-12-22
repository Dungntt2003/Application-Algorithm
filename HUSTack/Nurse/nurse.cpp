#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
const int MOD = 1e9 + 7;
int n, k1, k2;
int mem[N][2];

int dp(int i, int work) // work = 1 : ngày làm việc, work = 0 : ngày nghỉ
{
    if (i == 0)
        return mem[i][work] = 1;
    if (mem[i][work] != 0)
        return mem[i][work];
    int res = 0;
    if (work == 0)
    {
        res = dp(i - 1, 1) % MOD;
    }
    else
    {
        for (int j = i - k2; j <= i - k1; j++)
            if (j >= 0)
                res = (res + dp(j, 0)) % MOD;
    }
    return mem[i][work] = res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(mem, 0, sizeof(mem));
    cin >> n >> k1 >> k2;
    cout << dp(n, 1) + dp(n, 0);
    return 0;
}