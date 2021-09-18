#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define ii pair<int,int>  
// e[u],u

const int MAXN = 4 * 100000 + 9;
using namespace std;
int n;
int e[MAXN], deg[MAXN];
vector<int> a[MAXN];
int main() {
    cin >> n;
    for (int u = 1; u <= n; ++u)
    {
        int k = 0;
        cin >> e[u] >> k;
        int v = 0;
        for (int i = 1; i <= k; ++i)
        {
            cin >> v;
            a[u].push_back(v);
        }
    }
    priority_queue<ii, vector<ii>, greater<ii>> q;
    for (int u = 1; u <= n; ++u)
    {
        for (auto v : a[u])
            deg[v]++;
    }
    for (int u = 1; u <= n; ++u)
        if (deg[u] == 0) q.push(ii(e[u], u));
    int i = n - 1;
    int ans = -1;
    while (!q.empty())
    {
        int u = q.top().second;
        int cost = q.top().first + i;
        i--;
        ans = max(ans, cost);
        q.pop();

        for (auto v : a[u])
        {
            deg[v]--;
            if (deg[v] == 0)
                q.push(ii(e[v], v));
        }
    }

    cout << ans;
    return 0;
}