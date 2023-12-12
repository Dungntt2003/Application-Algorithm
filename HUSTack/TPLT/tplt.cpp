#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 4;
const int M = 1e5 + 4;
vector<int> Adj[N];
vector<int> iComponent(N, -1);
int n, m;

void Find_Component(int cur_comp, int u){
    if (iComponent[u] != -1) return;
    iComponent[u] = cur_comp;

    for (int i = 0 ; i < Adj[u].size(); i++){
        int v = Adj[u][i];
        Find_Component(cur_comp, v);
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
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("data.txt", "r", stdin);
    input();
    int num_comp = 0;
    for (int u = 1; u <= n ; u++){
        if (iComponent[u] == -1){
            Find_Component(num_comp, u);
            num_comp++;
        }
    }
    cout << num_comp << endl;
    return 0;
}