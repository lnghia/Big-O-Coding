#include <bits/stdc++.h>

using namespace std;

struct option{
	bool operator()(pair<int, int> a, pair<int, int> b) const{
		return a.second>b.second;
	}
};

void dijkstra(vector<vector<pair<int, int> > > &graph, vector<int> &path, vector<int> &dist, int u){
	priority_queue<pair<int, int>, vector<pair<int, int> >, option> q;

	q.push(make_pair(u, 0));
	dist[u]=0;
	while(!q.empty()){
		pair<int, int> tmp=q.top();

		q.pop();
		for(int i=0; i<graph[tmp.first].size(); ++i){
			int v=graph[tmp.first][i].first;
			int w=graph[tmp.first][i].second;

			if(w+tmp.second<dist[v]){
				dist[v]=w+tmp.second;
				path[v]=tmp.first;
				q.push(make_pair(v, dist[v]));
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, src, des, w, u, q, v;
	vector<vector<pair<int, int> > > graph(501);
	vector<int> path(501, -1);
	vector<int> dist(501, 1e9);

	cin >> n;
	while(n--){
		cin >> src >> des >> w;
		graph[src].push_back(make_pair(des, w));
		graph[des].push_back(make_pair(src, w));
	}
	cin >> u;
	dijkstra(graph, path, dist, u);
	cin >> q;
	while(q--){
		cin >> v;
		if(dist[v]==1e9){
			cout << "NO PATH\n";

			continue;
		}
		else{
			cout << dist[v] << '\n';
		}
	}

	return 0;
}