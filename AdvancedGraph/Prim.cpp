#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int N = 1e4 + 5;
int n, m;
struct edge {
    int u, v , w;
    edge(int _u, int _v, int _w) :
    u(_u), v(_v), w(_w){}
};
// vector<int> adj[N];
vector <vector <int> > adj;
vector<edge> Prim (int start,const vector <vector<edge>> &adj){
    int n = adj.size() -1 ;
    vector<bool> inTree(n + 5, false);
    vector<int> dist(n + 5, INF);
    vector<int> near(n + 5, -1);
    dist[start] = 0;
    vector<edge> res;

    while (res.size() < n - 1){
        int u = -1, v = -1 , minDist = -1;
        for (int x = 1 ; x <= n ; x++){
            if (!inTree[x] && dist[x] < minDist){
                minDist = dist[x];
                v = x;
                u = near[v];
            }
        }
        if (v == -1) return res;
        inTree[v] = true;
        if (v !== start) res.push_back(edge(u, v, minDist));

        for (const edge &e: adj[v]){
            int u = e.v, w = e.w;
            if (dist[u] > w){
                dist[u] = w;
                near[u] = v;
            }
        }
    }
    return res;
}


vector<edge> PrimPQ(int start, cosnt vector<vector<edge>> &adj){
    priority_queue<ii,vector<ii>, greater<ii>> PQ;
    int n = adj.size()-1;
    vector<int> dist(n+5 , INF);
    vector<int> near(n+5, -1);
    dist[start] = 0;
    PQ.push(make_pair(0, start));
    vector<edge> res;
    while (res.size() < n - 1){
        while (!PQ.empty() && PQ.top().first != dist[PQ.top().second]){
            PQ.pop();
        }
        if (PQ.empty()) return res;
        int v = PQ.top().second, minDist = PQ.top(), u = near[v];
        if (v != start) {
            res.push_back(edge(u, v, minDist));
        }
        for (const edge &e : adj[v]){
            int u = e.v, w = e.w;
            if (dist[u] > w){
                dist[u] = w;
                near[u] = v;
                PQ.push(make_pair(dist[u], u));
            }
        }
    }
    return res;
}

void input(){
    cin >> n >> m;
    int u,v,w;
    adj = vector<vector<edge>> (n + 5);
    for (int i = 0 ; i < m ; i++){
        cin >> u >> v >> w;
        adj[u].push_back(edge(u,v,w));
        adj[v].push_back(edge(v,u,w));
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("data.txt", "r", stdin);
    input();
    vector<edge> res = Prim(1, adj);
    for (const edge &e : res){
        cout << e.u << " " << e.v << " " << e.w << endl;
    }
    return 0;
}