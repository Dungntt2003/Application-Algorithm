#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
vector<int> Adj[N], Low(N), Num(N , -1);
int curnum = 0;
vector<pair<int , int>> Bridges;
int n, m;
void FindBridge(int u, int p){
    Low[u] = Num[u] = ++curnum;
    for (int i = 0 ; i < Adj[u].size(); i++){
        int v = Adj[u][i];
        if ( v == p) continue;
        if (Num[v] == -1) {
            FindBridge(v, u);
            Low[u] = min(Low[u], Low[v]);
        }
        else {
            Low[u] = min(Low[u], Num[v]);
        }
        if (Low[v] > Num[u]){
            cout << u << " " << v << endl;
            Bridges.push_back(make_pair(u,v));
        } 
    }
}

void input (){
    cin >> n >> m;
    int u, v ;
    for (int i = 0 ; i < m ; i++){
        cin >> u >> v;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }
}

int main(){
    freopen("data.txt", "r", stdin);
    input();
    for (int i = 1 ; i <= n ; i++){
        if (Num[i] == -1) FindBridge(i, -1);
    }
    return 0;
}