#include <bits/stdc++.h>

using namespace std;

bool bmf(vector<int> &junction, vector<pair<int, int> > &road, vector<int> &path, vector<int> &dist){
	int u, v, w;
	dist[1]=0;

	for(int i=1; i<=junction.size()-1; ++i){
		for(int j=0; j<road.size(); ++j){
			u=road[j].first;
			v=road[j].second;
			w=pow(junction[v]-junction[u], 3);
 			if(dist[u]!=1e9 && (dist[u]+w<dist[v])){
				dist[v]=dist[u]+w;
				path[v]=u;
			}
		}
	}

	for(int i=0; i<road.size(); ++i){
		u=road[i].first;
		v=road[i].second;
		w=pow(junction[v]-junction[u], 3);
		if(dist[u]!=1e9 && (dist[u]+w<dist[v])){
			return false;
		}
	}

	return true;
}

void solve(int a){
	vector<int> junction;
	vector<int> dist;
	vector<pair<int, int> > road;
	vector<int> path;
	vector<bool> 
	int tmp, n;
	bool temp=0;

	junction.resize(a+1); path.resize(a+1); dist.resize(a+1);
	for(int i=1; i<=a; ++i){
		cin >> tmp;

		junction[i]=tmp;
		path[i]=1e9;
		dist[i]=1e9;
	}

	cin >> n; 
	while(n--){
		int tmp1;

		cin >> tmp >> tmp1;
		road.push_back(make_pair(tmp, tmp1));
	}

	bmf(junction, road, path, dist);
	cin >> n;
	while(n--){
		cin >> tmp;

		if(dist[tmp]>=3 && dist[tmp]<1e9){
			cout << dist[tmp] << '\n';
		}
		else{
			cout << "?\n";
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;

	cin >> n;
	for(int i=0; i<n; ++i){
		int a;

		cin >> a;
		cout << "Case " << i+1 << ":\n";
		solve(a);
	}

	return 0;
}