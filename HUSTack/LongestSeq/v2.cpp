#include <bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(const vector<int>& X, const vector<int>& Y) {
    int n = X.size();
    int m = Y.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    vector<int> lcs;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs.push_back(X[i - 1]);
            i--;
            j--;
        } else if (dp[i - 1][j] >= dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    reverse(lcs.begin(), lcs.end());
    return lcs.size();
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> X(n);
    for (int i = 0; i < n; i++) {
        cin >> X[i];
    }
    vector<int> Y(m);
    for (int i = 0; i < m; i++) {
        cin >> Y[i];
    }
    int lcs = longestCommonSubsequence(X, Y);
    cout << lcs;
    cout << endl;

    return 0;
}