#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
vector<int> Adj[N];
vector<int> iComponent(N, -1);
int n, m;

void Find_Component(int cur_comp, int u){
    if (iComponent[u] != -1) return;
    iComponent[u] = cur_comp;
    for (const int &v : Adj[u]){
        if (iComponent[v] != -1)
        Find_Component(cur_comp, v);
    }
}

void input(){
    cin >> n >> m;
    int u, v;
    for (int i = 0 ; i < m ; i++){
        cin >> u >> v;
        Adj[u].push_back(v);
        // Adj[v].push_back(u);
    }
    // for (int i = 1 ; i <= n ; i++){
    //     sort(Adj[i].begin(), Adj[i].end());
    // }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("data.txt", "r", stdin);
    int num_comp = 0;
    for (int i = 1 ; i <= n ; i++){
        if (iComponent[i] == -1){
            num_comp ++;
            Find_Component(num_comp, i);
        }
    }
    cout << num_comp;
    return 0;
}