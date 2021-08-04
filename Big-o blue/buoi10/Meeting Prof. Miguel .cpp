#include <bits/stdc++.h>

using namespace std;

void floy(vector<vector<int> > &graph, vector<vector<int> > &dist){
	for(int k=0; k<graph.size(); ++k){
		for(int i=0; i<graph.size(); ++i){
			for(int j=0; j<graph.size(); ++j){
				if(dist[i][j]>dist[i][k]+dist[k][j]){
					dist[i][j]=dist[i][k]+dist[k][j];
				}
			}
		}
	}
}

void solve(int n){
	int c;
	char a, d, st, ds;
	vector<vector<int> > graph(26, vector<int>(26, 1e9));
	vector<vector<int> > _graph(26, vector<int>(26, 1e9));
	vector<vector<int> > dist(26, vector<int>(26, 1e9));
	vector<vector<int> > _dist(26, vector<int>(26, 1e9));
	char _st, _ds;
	int min1=1e9;
	vector<int> common_v;

	while(n--){
		cin >> a >> d >> st >> ds >> c;

		if(a=='Y'){
			graph[st-65][ds-65]=min(graph[st-65][ds-65], c);
			dist[st-65][ds-65]=graph[st-65][ds-65];
			if(d=='B'){
				graph[ds-65][st-65]=min(graph[st-65][ds-65], c);
				dist[ds-65][st-65]=graph[st-65][ds-65];
			}
		}
		else{
			_graph[st-65][ds-65]=min(_graph[st-65][ds-65], c);
			_dist[st-65][ds-65]=_graph[st-65][ds-65];
			if(d=='B'){
				_graph[ds-65][st-65]=min(_graph[st-65][ds-65], c);
				_dist[ds-65][st-65]=_graph[st-65][ds-65];
			}
		}
	}
	cin >> _st >> _ds;
	for(int i=0; i<26; ++i){
		for(int j=0; j<26; ++j){
			if(i==j){
				dist[i][j]=dist[j][i]=0;
				_dist[i][j]=_dist[j][i]=0;
				graph[i][j]=graph[j][i]=0;
				_graph[i][j]=_graph[j][i]=0;
			}
		}
	}
	
	floy(graph, dist);
	floy(_graph, _dist);

	for(int i=0; i<26; ++i){
		if(dist[_st-65][i]+_dist[_ds-65][i]<min1){
			min1=dist[_st-65][i]+_dist[_ds-65][i];
		}
	}
	for(int i=0; i<26; ++i){
		if(dist[_st-65][i]+_dist[_ds-65][i]==min1 && min1!=1e9){
			common_v.push_back(i);
		}
	}

	sort(common_v.begin(), common_v.end());
	if(!common_v.size()){
		cout << "You will never meet." << '\n';

		return;
	}
	cout << min1;
	for(int i=0; i<common_v.size(); ++i){
		cout << ' ' << char(common_v[i]+65);
	}
	cout << '\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;

	while(1){
		cin >> n;
		if(!n){
			return 0;
		}
		solve(n);
	}

	return 0;
}