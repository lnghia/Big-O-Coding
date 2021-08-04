#include <bits/stdc++.h>

using namespace std;

struct edge{
	int s;
	int d;
	int w;

	edge(int a, int b, int c){
		s=a;
		d=b;
		w=c;
	}
};

void bmf(int s, vector<edge> &graph, vector<int> &dist, vector<bool> &check, vector<int> &path){
	int u, v, w;
	dist[s]=0;

	for(int i=1; i<dist.size(); ++i){
		for(int j=0; j<graph.size(); ++j){
			u=graph[j].s;
			v=graph[j].d;
			w=graph[j].w;
			if(dist[u]!=1e9 && dist[u]+w<dist[v]){
				dist[v]=dist[u]+w;
				path[v]=u;
			}
		}
	}

	for(int i=0; i<dist.size(); ++i){
		for(int j=0; j<graph.size(); ++j){
			u=graph[j].s;
			v=graph[j].d;
			w=graph[j].w;
			if(dist[u]!=1e9 && dist[u]+w<dist[v]){
				dist[v]=dist[u]+w;
				check[v]=1;
				check[u]=1;
			}
		}
	}
}

void solve(int n, int m, int q, int s){
	vector<edge> graph;
	vector<int> dist(n, 1e9);
	vector<bool> check(n, 0);
	vector<int> path(n, -1);
	int u, v, w;

	for(int i=0; i<m; ++i){
		cin >> u >> v >> w;
		graph.push_back(edge(u, v, w));
	}
	bmf(s, graph, dist, check, path);

	while(q--){
		cin >> v;
		if(!check[v]){
			if(dist[v]<1e9){
				cout << dist[v] << '\n';
			}
			else{
				cout << "Impossible\n";
			}
		}
		else{
			cout << "-Infinity\n";
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, q, s;

	while(1){
		cin >> n >> m >> q >> s;
		if(!n){
			return 0;
		}
		solve(n, m, q, s);
		cout << '\n';
	}

	return 0;
}