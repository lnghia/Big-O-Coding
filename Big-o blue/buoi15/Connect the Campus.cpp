#include <bits/stdc++.h>

using namespace std;

double cal_dis(pair<double, double> building1, pair<double, double> building2){
	return sqrt(pow((building2.first-building1.first), 2)+pow((building2.second-building1.second), 2));
}

struct option{
	bool operator()(pair<int, double> a, pair<int, double> b) const{
		return a.second>b.second;
	}
};

double prim(vector<vector<pair<int, double> > > &graph){
	double ans=0;
	vector<bool> visited(graph.size(), 0);
	vector<double> dist(graph.size(), 1e9);
	priority_queue<pair<int, double>, vector<pair<int, double> >, option> q;

	q.push(make_pair(1, 0));
	dist[1]=0;
	while(!q.empty()){
		int u=q.top().first;

		q.pop();
		visited[u]=1;
		for(int i=0; i<graph[u].size(); ++i){
			int v=graph[u][i].first;
			double w=graph[u][i].second;

			if(!visited[v] && dist[v]>w){
				dist[v]=w;
				q.push(make_pair(v, w));
			}
		}
	}

	for(int i=1; i<dist.size(); ++i){
		ans+=(dist[i]<1e9 && dist[i]>=0)?dist[i]:0;
	}

	return ans;
}

double solve(int n){
	int t, building_src, building_des;
	double x, y;
	vector<pair<double, double> > buildings;
	vector<vector<pair<int, double> > > graph(n+1);

	for(int i=0; i<n; ++i){
		cin >> x >> y;
		buildings.push_back(make_pair(x, y));
	}

	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			double distance=cal_dis(buildings[i], buildings[j]);

			graph[i+1].push_back(make_pair(j+1, distance));
			graph[j+1].push_back(make_pair(i+1, distance));
		}
	}

	cin >> t;
	while(t--){
		cin >> building_src >> building_des;
		for(int i=0; i<graph[building_src].size(); ++i){
			if(graph[building_src][i].first==building_des){
				graph[building_src][i].second*=-1;

				break;
			}
		}
		for(int i=0; i<graph[building_des].size(); ++i){
			if(graph[building_des][i].first==building_src){
				graph[building_des][i].second*=-1;

				break;
			}
		}
	} 

	return prim(graph);
}

int main(){
	/*ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);*/
	int n;
	//freopen("E:\\Big-o blue\\buoi15\\input.txt", "r", stdout);

	while(cin>>n){
		cout << fixed << setprecision(2) << solve(n) << '\n';
	}

	return 0;
}