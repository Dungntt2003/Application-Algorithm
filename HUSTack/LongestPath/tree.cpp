#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX

struct Edge {
    int to, weight;
};

void dijkstra(vector<vector<Edge>>& graph, int start, vector<int>& distance) {
    priority_queue<pair<int, int>> pq;
    distance[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int dist = -pq.top().first;
        pq.pop();

        if (dist > distance[u]) continue;

        for (Edge& e : graph[u]) {
            int v = e.to;
            int w = e.weight;

            if (distance[v] > distance[u] + w) {
                distance[v] = distance[u] + w;
                pq.push({-distance[v], v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("inp.txt", "r", stdin);
    int n, m; 
    cin >> n >> m;

    vector<vector<Edge>> graph(n + 1);
    vector<int> distance(n + 1, INF);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    int start = 1; 

    dijkstra(graph, start, distance);

    int maxDistance = 0;
    for (int i = 1; i <= n; ++i) {
        if (distance[i] != INF && distance[i] > maxDistance) {
            maxDistance = distance[i];
        }
    }

    cout << "Trong so cua duong di dai nhat: " << maxDistance << endl;

    return 0;
}
