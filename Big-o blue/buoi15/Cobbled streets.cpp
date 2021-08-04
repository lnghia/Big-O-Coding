#include <bits/stdc++.h>

using namespace std;

struct option{
	bool operator()(const pair<int, int> &a, const pair<int, int> &b) const{
		return a.second>b.second;
	}
};

int prim(vector<vector<pair<int, int> > > &graph, const int &p){
	int sum=0;
	priority_queue<pair<int, int>, vector<pair<int, int> >, option> q;
	vector<bool> visited(graph.size(), 0);
	vector<int> dist(graph.size(), 1e9);

	q.push(make_pair(1, 0));
	dist[1]=0;
	while(!q.empty()){
		int u=q.top().first;

		q.pop();
		visited[u]=1;
		for(int i=0; i<graph[u].size(); ++i){
			int v=graph[u][i].first;
			int w=graph[u][i].second;

			if(!visited[v] && dist[v]>w){
				dist[v]=w;
				q.push(make_pair(v, w));
			}
		}
	}

	for(int i=1; i<dist.size(); ++i){
		sum+=(dist[i]<1e9)?dist[i]:0;
	}

	return sum*p;
}

int solve(int p, int n, int m){
	int ans=0, a, b, c;
	vector<vector<pair<int, int> > > graph(n+1);

	while(m--){
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, c));
	}

	ans=prim(graph, p);

	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, p, n, m;

	cin >> t;
	while(t--){
		cin >> p >> n >> m;
		cout << solve(p, n, m) << '\n';
	}

	return 0;
}