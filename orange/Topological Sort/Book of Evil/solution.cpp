#include <bits/stdc++.h>
#define eb emplace_back
using namespace std;
const int inf = 1e9;

typedef vector<int> vi;
typedef vector<vi> graph_type;

void dfs(graph_type& adj, vi& dist, const vector<bool>& affected, int u, int d) {
    dist[u] = -inf;
    if (affected[u]) {  
        dist[u] = d;
    }
    
    for (int v : adj[u]) {
        if (dist[v] == -1) {
            dfs(adj, dist, affected, v, d + 1);
        }
    }
}

int main() {
    int n, m, d;
    cin >> n >> m >> d;
    
    vector<bool> affected(n);
    for (int i = 0, p; i < m; ++i) {
        cin >> p;
        affected[p - 1] = true;
    }
    
    graph_type adj(n);
    for (int i = 1, x, y; i < n; ++i) {
        cin >> x >> y;
        --x; --y;
        adj[x].eb(y);
        adj[y].eb(x);
    }
    
    vi dist0(n, -1), distu(n, -1), distv(n, -1);
    dfs(adj, dist0, affected, 0, 0);
    int u = std::max_element(dist0.begin(), dist0.end()) - dist0.begin();
    dfs(adj, distu, affected, u, 0);
    int v = std::max_element(distu.begin(), distu.end()) - distu.begin();

    distu = vi(n, -1);
    dfs(adj, distu, vector<bool>(n, true), u, 0);
    dfs(adj, distv, vector<bool>(n, true), v, 0);

    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (max(distu[i], distv[i]) <= d) {
            res++;
        }
    }
    
    cout << res;
}