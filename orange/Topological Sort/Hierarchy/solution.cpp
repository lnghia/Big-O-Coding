#include <bits/stdc++.h>
using namespace std;

void dfs(int u, const vector<vector<int>> &graph, vector<bool> &visited, vector<int> &result) {
    visited[u] = true;
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if (!visited[v]) {
            dfs(v, graph, visited, result);
        }
    }
    result.push_back(u);
}

vector<int> topologicalSort(const vector<vector<int>> &graph) {
    int V = graph.size();
    vector<int> result;
    result.reserve(V);
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, graph, visited, result);
        }
    }
    std::reverse(result.begin(), result.end());
    return result;
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<vector<int>> graph(n);
    for (int u = 0; u < k; ++u) {
        int w, v;
        scanf("%d", &w);
        while (w--) {
            scanf("%d", &v);
            graph[u].push_back(v - 1);
        }
    }

    auto topo_order = topologicalSort(graph);
    vector<int> boss(n);
    boss[topo_order[0]] = -1;
    for (int i = 1; i < n; ++i) {
        boss[topo_order[i]] = topo_order[i - 1];
    }
    
    for (int i = 0; i < n; ++i) {
        printf("%d\n", boss[i] + 1);
    }
}