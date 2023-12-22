#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
};

struct DisjointSet {
    vector<int> parent, rank;
    
    DisjointSet(int n) {
        parent.resize(n);
        rank.assign(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;
        if (rank[u] < rank[v]) {
            parent[u] = v;
        } else if (rank[u] > rank[v]) {
            parent[v] = u;
        } else {
            parent[v] = u;
            rank[u]++;
        }
    }
};

int kruskalMST(vector<Edge>& edges, int n) {
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    DisjointSet ds(n);
    int minWeight = 0;

    for (const Edge& edge : edges) {
        int u = edge.u;
        int v = edge.v;
        int w = edge.weight;

        if (ds.find(u) != ds.find(v)) {
            minWeight += w;
            ds.unite(u, v);
        }
    }

    return minWeight;
}

int main() {
    int n, m; 
    // freopen("data.txt", "r", stdin);
    cin >> n >> m;

    vector<Edge> edges(m);

    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    int minWeight = kruskalMST(edges, n);
    cout << "Trong so cua cay khung nho nhat: " << minWeight << endl;

    // cout << n << " " << m << endl;
    //  for (int i = 0; i < m; ++i) {
    // cout << edges[i].u << edges[i].v << edges[i].weight << endl;
    // }
    return 0;
}
