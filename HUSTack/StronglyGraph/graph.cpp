#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int n,m ;
vector<int> Adj[N], Low(N), Num(N, -1);
vector<bool> bConnect(N, false);
int curnum = 0;
stack<int> iComp;
int res = 0;

void SCC(int u){
    iComp.push(u);
    bConnect[u] = true;
    Low[u] = Num[u] = ++curnum;

    for (int i = 0 ; i < Adj[u].size(); i++){
        int v = Adj[u][i];
        if (Num[v] == -1){
            SCC(v);
            Low[u] = min(Low[u], Low[v]);
        }
        else if (bConnect[v]){
            Low[u] = min(Low[u], Num[v]);
        }
    }

    if (Num[u] == Low[u]){
        while (true){
            int cur = iComp.top();
            iComp.pop();
            bConnect[cur] = false;
            if (cur == u) break;
        }
        res++;
    }
}

void input(){
    cin >> n >> m;
    int u, v;
    for (int i = 0 ; i < m ; i++){
        cin >> u >> v;
        Adj[u].push_back(v);
    }
}

int main(){
    // freopen("data.txt", "r", stdin);
    input();
    for (int i = 1 ; i <= n ; i++){
        if (Num[i] == -1){
            SCC(i);
        }
    }
    cout << res << endl;
    return 0;
}