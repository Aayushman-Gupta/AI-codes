#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N]; // adjacency list
bool visited[N];     // visited array

void dfs(int node) {
    visited[node] = true;
    cout << "Visited: " << node << endl;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m; // n = number of nodes, m = number of edges

    // build the undirected graph
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // start DFS from node 1 (or any unvisited node)
    dfs(1);

    return 0;
}
