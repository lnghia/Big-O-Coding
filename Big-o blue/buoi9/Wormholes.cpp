#include <bits/stdc++.h>

using namespace std;

struct edge{
	int start;
	int des;
	int weight;

	edge(int s, int d, int w){
		start=s;
		des=d;
		weight=w;
	}
};

bool BellmanFord(int s, int n, int m, vector<edge> &graph, vector<int> &dist, vector<int> &path){
	int u, v, w;

	dist[s]=0;
	for(int i=1; i<n-1; ++i){
		for(int j=0; j<m; ++j){
			u=graph[j].start;
			v=graph[j].des;
			w=graph[j].weight;
			if(dist[u]!=1e9 && (dist[u]+w<dist[v])){
				dist[v]=dist[u]+w;
				path[v]=u;
			}
		}
	}

	for(int i=0; i<m; ++i){
		u=graph[i].start;
		v=graph[i].des;
		w=graph[i].weight;
		if(dist[u]!=1e9 && (dist[u]+w<dist[v])){
			return false;
		}
	}

	return true;
}

string solve(int v, int e){
	vector<edge> graph;
	vector<int> dist(v, 1e9);
	vector<int> path(v, -1);
	string ans="not possible";

	for(int i=0; i<e; ++i){
		int a, b, c;

		cin >> a >> b >> c;
		graph.push_back(edge(a, b, c));
	}

	if(!BellmanFord(0, v, e, graph, dist, path)){
		ans="possible";
	}

	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;

	cin >> n;
	while(n--){
		int e, v;

		cin >> v >> e;
		cout << solve(v, e) << '\n';
	}

	return 0;
}