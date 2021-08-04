#include <bits/stdc++.h>

using namespace std;

void Floy(vector<vector<int> > &dist, vector<vector<bool> > &graph, vector<vector<int> > &path){ 

	for(int k=0; k<graph.size(); ++k){
		for(int i=0; i<graph.size(); ++i){
			for(int j=0; j<graph.size(); ++j){
				if(dist[i][j]>(dist[i][k]+dist[k][j])){
					dist[i][j]=dist[i][k]+dist[k][j];
					path[i][j]=path[k][j];
				}
			}
		}
	}
}

pair<int, int> solve(vector<string> input){
	pair<int, int> ans;
	int m=input[0].size();
	char tmp;
	string tmp1;
	vector<vector<bool> > graph(m, vector<bool>(m, 0));
	vector<vector<int> > dist(m, vector<int>(m, 3));
	vector<vector<int> > path(m, vector<int>(m, -1));

	/*for(int i=0; i<m; ++i){
		graph[i].resize(m, 0); dist[i].resize(m, 2); path[i].resize(m, -1);
	}*/
	for(int i=0; i<input.size(); ++i){
		for(int j=0; j<input[i].size(); ++j){
			if(input[i][j]=='Y'){
				graph[i][j]=1;
				graph[j][i]=1;
				dist[i][j]=1;
				dist[j][i]=1;
			}
			if(graph[i][j]!=0 && i!=j){
				path[i][j]=i;
			}
			if(i==j){
				dist[i][j]=0;
				graph[i][j]=0;
			}
		}
	}
	Floy(dist, graph, path);
	//cout << '\n';
	int max1=0, pos=0;

	for(int i=0; i<m; ++i){
		int count=0;
		for(int j=0; j<m; ++j){
			count+=(dist[i][j]==2);
		}
		if(max1<count){
			pos=i;
			max1=count;
		}
	}

	return make_pair(pos, max1);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("E:\\Big-o blue\\buoi10\\input.txt", "r", stdin);
	int n;
	int i=0, j=0, _i=1;
	string tmp;
	vector<string> input;
	vector<int> length;
	int t=0, test=1;

	cin >> n;
	for(int i=0; i<n; ++i){
		vector<string> _input;

		cin >> tmp;
		_input.push_back(tmp);
		for(int j=0; j<tmp.length()-1; ++j){
			cin >> tmp;
			_input.push_back(tmp);
		}
		pair<int, int> ans=solve(_input);
		cout << ans.first << ' ' << ans.second << '\n';
	}

	return 0;
}