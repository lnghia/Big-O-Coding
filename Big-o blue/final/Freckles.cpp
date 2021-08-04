#include <bits/stdc++.h>

using namespace std;

struct option{
	bool operator()(pair<int, double> a, pair<int, double> b)const{
		return a.second>b.second;
	}
};

void prim(vector<vector<pair<int, double> > > &graph, vector<double> &dist, vector<bool> &visited){
	priority_queue<pair<int, double>, vector<pair<int, double> >, option> q;
	q.push(make_pair(0, 0));
	dist[0]=0;

	while(!q.empty()){
		int u=q.top().first;

		visited[u]=1;
		q.pop();
		for(int i=0; i<graph[u].size(); ++i){
			int v=graph[u][i].first;
			double w=graph[u][i].second;
			//cout << fixed << setprecision(3) << w << '\n';
			if(!visited[v] && dist[v]>w){
				dist[v]=w;
				q.push(make_pair(v, dist[v]));
			}
		}
	}
}

double solve(int n){
	double ans=0;
	vector<pair<double, double> > dots;
	vector<vector<pair<int, double> > > graph(n);
	vector<bool> visited(n, 0);
	vector<double> dist(n, 1e9);

	for(int i=0; i<n; ++i){
		double x, y;

		cin >> x >> y;
		dots.push_back(make_pair(x, y));
	}

	for(int i=0; i<dots.size(); ++i){
		for(int j=0; j<dots.size(); ++j){
			double w=sqrt(pow((dots[j].first-dots[i].first), 2)+pow((dots[j].second-dots[i].second), 2));
			//cout << w << '\n';
			graph[i].push_back(make_pair(j, w));
			graph[j].push_back(make_pair(i, w));
		}
	}

	prim(graph, dist, visited);

	for(int i=0; i<dist.size(); ++i){
		//cout << fixed << setprecision(2) << dist[i] << '\n';
		ans+=(dist[i]<1e9)?dist[i]:0;
	}

	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, n;

	cin >> t;
	while(t--){
		cin >> n;
		cout << fixed << setprecision(2) << solve(n);
		if(t>=1){
			cout << '\n' << '\n';
		}
	}

	return 0;
}