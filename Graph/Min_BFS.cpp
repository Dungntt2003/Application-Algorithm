#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
vector<int> Adj[N];
// vector<bool> visited(N, false);
vector<int> Dist(N, -1);
queue<int> Q;
int n, m;
int a, b;


void MinBFS(int a){
    Q.push(a);
    Dist[a] = 0;

    while (!Q.empty()){
        int u = Q.front(); Q.pop();
        for (int i = 0 ; i < Adj[u].size(); i++){
            int v = Adj[u][i];
            if (Dist[v] == -1){
                Q.push(v);
                Dist[v] = 1 + Dist[u];
            }
        }
    }
}

void input(){
    cin >> n >> m;
    int u, v;
    for (int i = 0 ; i < m ; i++){
        cin >> u >> v;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }
    cin >> a >> b;
}

int main(){
    freopen("data.txt", "r", stdin);
    input();
    // int a,b;
    MinBFS(a);
    cout << Dist[b] << endl;
    return 0;
}