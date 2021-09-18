#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Employee {
    int index;
    int rank;

    Employee(int index, int rank) : index(index), rank(rank) {}
};

void dfs(int u, vector<vector<int>>& adj, vector<int>& visited, vector<int>& topoOrder) {
    visited[u] = 1;

    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, adj, visited, topoOrder);
        }
    }

    topoOrder.push_back(u);
}

vector<int> topoSort(vector<vector<int>>& adj) {
    vector<int> topoOrder;
    int n = adj.size();
    vector<int> visited(n, 0);

    for (int u = 0; u < n; u++) {
        if (!visited[u]) {
            dfs(u, adj, visited, topoOrder);
        }
    }

    reverse(topoOrder.begin(), topoOrder.end());

    return topoOrder;
}

void solveTest(int testNumber) {
    int n, r;
    cin >> n >> r;

    vector<vector<int>> adj(n, vector<int>());
    vector<int> inDeg(n, 0);

    for (int i = 0; i < r; i++) {
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
        ++inDeg[u];
    }

    vector<int> topoOrder = topoSort(adj);
    vector<int> rank(n);

    for (int u  : topoOrder) {
        if (inDeg[u] == 0) {
            rank[u] = 1;
        }
        for (int v : adj[u]) {
            rank[v] = max(rank[v], rank[u] + 1);
        }
    }

    vector<Employee> employees;

    for (int u = 0; u < n; u++) {
        employees.push_back(Employee(u, rank[u]));
    }

    sort(employees.begin(), employees.end(), [](const Employee& e1, const Employee& e2) {
        if (e1.rank == e2.rank) {
            return e1.index < e2.index;
        }
        return e1.rank < e2.rank;
    });
    
    cout << "Scenario #" << testNumber << ":\n";

    for (Employee& e : employees) {
        cout << e.rank << ' ' << e.index << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int testNumber = 1; testNumber <= t; testNumber++) {
        solveTest(testNumber);
    }    

    return 0;
}