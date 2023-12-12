#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
vector<int> Adj[N], iOrder;
vector<bool> visited(N, false);
int n , m;

void TopoSort(int u){
    if (visited[u]) return;

    visited[u] = true;
    for (int i = 0 ; i < Adj[u].size(); i++){
        int v = Adj[u][i];
        TopoSort(v);
    }
    iOrder.push_back(u);
}

void input(){
    cin >> n >> m;
    int u,v ;
    for (int i = 0 ; i < m ; i++){
        cin >> u >> v;
        Adj[u].push_back(v);
    }
}

int main(){
    freopen("data.txt", "r", stdin);
    input();
    for (int i = 1 ; i <= n ; i++){
        if (!visited[i]) TopoSort(i);
    }
    for (int i = iOrder.size() - 1; i >= 0 ; i--)
    cout << iOrder[i] << " ";
    return 0;
}