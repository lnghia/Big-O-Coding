#include <iostream>
#include <map>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int V, E;

vector<int> topologicalSort(vector<vector<int>> &graph)
{
    vector<int> indegree(V, 0);
    vector<int> result;
    priority_queue<int, vector<int>, greater<int> > zero_indegree;

    for (int u = 0; u<V; u++)
    {
        vector<int>::iterator it;
        for (it = graph[u].begin(); it != graph[u].end(); it++)
            indegree[*it]++;
    }

    for (int i = 0; i < V; i++) {
        if (indegree[i]==0) {
            zero_indegree.push(i);
        }
    }

    while (!zero_indegree.empty())
    {
        int u = zero_indegree.top();
        zero_indegree.pop();

        result.push_back(u);

        vector<int>::iterator it;
        for (it = graph[u].begin(); it != graph[u].end(); it++)
        {
            indegree[*it]--;
            if (indegree[*it]==0) {
                zero_indegree.push(*it);
            }
        }
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);

    int iTest = 0;
    while (cin >> V) {
        ++iTest;

        vector<string> name(V);
        for(int u = 0; u < V; ++u)
            cin >> name[u];

        map<string, int> id;
        for(int u = 0; u < V; ++u)
            id[name[u]] = u;

        vector<vector<int>> graph;
        graph.assign(V, vector<int>());

        cin >> E;
        for(int i = 0; i < E; ++i) {
            string nameU, nameV;
            cin >> nameU >> nameV;
            int u = id[nameU], v = id[nameV];
            graph[u].push_back(v);
        }

        vector<int> topoOrd = topologicalSort(graph);

        cout << "Case #" << iTest << ": Dilbert should drink beverages in this order:";
        for(int u: topoOrd)
            cout << " " << name[u];
        cout << "." << endl;
        cout << endl;
    }

    return 0;
}