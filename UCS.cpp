#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>
using namespace std;

const int N = 1e5 + 5;
vector<pair<int, int>> adj[N]; // adj[node] = {neighbor, cost}

void uniformCostSearch(int start, int goal, int n) {
    vector<int> dist(n + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[start] = 0;
    pq.push({0, start}); // {cost, node}

    while (!pq.empty()) {
        auto [cost, node] = pq.top();
        pq.pop();

        if (node == goal) {
            cout << "Minimum cost from " << start << " to " << goal << " is: " << cost << endl;
            return;
        }

        for (auto [neighbor, weight] : adj[node]) {
            if (cost + weight < dist[neighbor]) {
                dist[neighbor] = cost + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }

    cout << "No path exists from " << start << " to " << goal << endl;
}

int main() {
    int n, m;
    cin >> n >> m; // n = number of nodes, m = number of edges

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w; // edge from u to v with weight w
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // if undirected
    }

    int start, goal;
    cin >> start >> goal;

    uniformCostSearch(start, goal, n);

    return 0;
}
