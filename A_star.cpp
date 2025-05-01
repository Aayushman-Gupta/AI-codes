#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
using namespace std;

const int INF = INT_MAX;
vector<pair<int, int>> adj[100]; // adjacency list: node -> {neighbor, cost}
unordered_map<int, int> h;       // heuristic values

// A* Search Function
void a_star(int start, int goal) {
    unordered_map<int, int> g; // cost from start to node
    unordered_map<int, int> f; // estimated total cost
    unordered_map<int, int> parent;

    for (int i = 0; i < 100; ++i) {
        g[i] = INF;
        f[i] = INF;
    }

    g[start] = 0;
    f[start] = h[start];

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> open_set;
    open_set.push({f[start], start});

    while (!open_set.empty()) {
        int current = open_set.top().second;
        open_set.pop();

        cout << "Visiting: " << current << endl;

        if (current == goal) {
            cout << "Reached goal!\nPath: ";
            vector<int> path;
            for (int node = goal; node != start; node = parent[node]) {
                path.push_back(node);
            }
            path.push_back(start);
            reverse(path.begin(), path.end());
            for (int n : path) cout << n << " ";
            cout << endl;
            return;
        }

        for (auto [neighbor, cost] : adj[current]) {
            int tentative_g = g[current] + cost;
            if (tentative_g < g[neighbor]) {
                parent[neighbor] = current;
                g[neighbor] = tentative_g;
                f[neighbor] = g[neighbor] + h[neighbor];
                open_set.push({f[neighbor], neighbor});
            }
        }
    }

    cout << "Goal not reachable.\n";
}

int main() {
    // Define the graph edges (node1, node2, cost)
    adj[1].push_back({2, 2});
    adj[1].push_back({3, 4});
    adj[2].push_back({4, 7});
    adj[3].push_back({4, 1});
    adj[4].push_back({5, 3});

    // Define heuristic values (h[n] = estimated cost to goal = 5)
    h[1] = 7;
    h[2] = 6;
    h[3] = 2;
    h[4] = 1;
    h[5] = 0;

    a_star(1, 5); // Start = 1, Goal = 5
    return 0;
}
