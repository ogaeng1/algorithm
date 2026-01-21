#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int parent[100001];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) parent[y] = x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E;
    cin >> V >> E;

    for (int i = 1; i <= V; i++) parent[i] = i;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        pq.push({c, {a, b}});
    }

    long long res = 0;
    int edge_count = 0;

    while (!pq.empty() && edge_count < V - 1) {
        int weight = pq.top().first;
        int u = pq.top().second.first;
        int v = pq.top().second.second;
        pq.pop();

        if (find(u) != find(v)) {
            unite(u, v);
            res += weight;
            edge_count++;
        }
    }

    cout << res << "\n";

    return 0;
}
