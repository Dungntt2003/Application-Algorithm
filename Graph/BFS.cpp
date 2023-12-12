#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int n, m;
vector<int> Adj[N];
vector<bool> visited(N, false);
queue<int> Q;


void BFS(){
    Q.push(1);
    visited[1] = true;

    while (!Q.empty()){
        int u = Q.front(); Q.pop();
        cout << u << " ";
        for (int i = 0 ; i < Adj[u].size(); i++){
            int v = Adj[u][i];
            if (!visited[v]){
                Q.push(v);
                visited[v] = true;
            }
        }
    }
}

void input(){
    cin >> n >> m;
    int u, v;
    for (int i=0; i<m; i++) {
        cin >> u >> v;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }
}

int main(){
    freopen("data.txt", "r", stdin);
    input();
    // cout << 1 << " ";
    BFS();
    return 0;
}