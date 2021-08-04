#include <bits/stdc++.h>

using namespace std;

struct option{
	bool operator()(const pair<long long, long long> &a, const pair<long long, long long> &b) const
	{
		return a.second>b.second;
	}
};

long long solve(vector<vector<pair<long long, long long> > > &graph){
	vector<long long> dist(graph.size(), 1e9);
	vector<bool> visited(graph.size(), 0);
	priority_queue<pair<long long, long long>, vector<pair<long long, long long> >, option> p;
	long long ans=0;

	p.push(make_pair(1, 0));
	dist[1]=0;
	while(!p.empty()){
		long long u=p.top().first;

		p.pop();
		visited[u]=1;
		for(long long i=0; i<graph[u].size(); ++i){
			long long v=graph[u][i].first;
			long long w=graph[u][i].second;

			if(!visited[v] && dist[v]>w){
				dist[v]=w;
				p.push(make_pair(v, w));
			}
		}
	}

	for(long long i=1; i<dist.size(); ++i){
		ans+=(dist[i]<1e9)?dist[i]:0;
	}

	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long m, n, u, v, w;
	vector<vector<pair<long long, long long> > > graph;

	cin >> n >> m;
	graph.resize(n+1);
	for(long long i=0; i<m; ++i){
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v, w));
		graph[v].push_back(make_pair(u, w));
	}
	cout << solve(graph);

	return 0;
}