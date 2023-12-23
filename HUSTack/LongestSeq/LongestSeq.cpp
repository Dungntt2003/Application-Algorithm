#include <bits/stdc++.h>
using namespace std;

int n, m;
const int N = 1e4 + 5;
int A[N];
int B[N];
int iMem[N][N];

int LCS(int i, int j) {
    if (i == 0 || j == 0) return 0;
    if (iMem[i][j] != -1) return iMem[i][j];

    int res = 0;
    res = max(res, LCS(i, j - 1));
    res = max(res, LCS(i - 1, j));
    if (A[i] == B[j])
        res = max(res, LCS(i - 1, j - 1) + 1);
    iMem[i][j] = res;
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(iMem, -1, sizeof(iMem));
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> B[i];
    }
    cout << LCS(n-1, m-1) + 1 << endl;
    return 0;
}