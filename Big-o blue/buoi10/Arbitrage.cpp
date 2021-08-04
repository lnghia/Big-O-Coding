#include <bits/stdc++.h>

using namespace std;

void floy(vector<vector<double> > &graph, vector<vector<double> > &dist, vector<vector<int> > &path){
	for(int i=0 ;i<graph.size(); ++i){
		for(int j=0; j<graph.size(); ++j){
			for(int k=0; k<graph.size(); ++k){
				if(dist[j][i]!=-1 && dist[i][k]!=-1){
					if(dist[j][k]<dist[j][i]*dist[i][k]){
						dist[j][k]=dist[j][i]*dist[i][k];
						path[j][k]=path[i][k];
					}
				}
			}
		}
	}
}

string solve(int n){
	map<string, int> currencies;
	vector<string> _currencies;
	vector<vector<double> > graph(n, vector<double>(n, -1));
	vector<vector<double> > dist(n, vector<double>(n, -1));
	vector<vector<int> > path(n, vector<int>(n, -1));
	string tmp, ans="Yes";
	int temp;
	string src, des;
	double rate;

	for(int i=0; i<n; ++i){
		cin >> tmp;
		currencies.insert(make_pair(tmp, i));
		_currencies.push_back(tmp);
	}
	
	cin >> temp;
	while(temp--){
		cin >> src >> rate >> des;
		graph[currencies[src]][currencies[des]]=max(rate, graph[currencies[src]][currencies[des]]);
		dist[currencies[src]][currencies[des]]=max(rate, graph[currencies[src]][currencies[des]]);
		path[currencies[src]][currencies[des]]=currencies[src];
	}
	
	floy(graph, dist, path);
	/*for(int i=0; i<graph.size(); ++i){
		for(int j=0; j<graph.size(); ++j){
			cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}*/
	if(dist[currencies["USDollar"]][currencies["USDollar"]]<=1){
		ans="No";
	}

	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, i=1;

	while(i){
		cin >> n;
		if(!n){
			return 0;
		}
		cout << "Case " << i++ << ": " << solve(n) << '\n';
	}

	return 0;
}
