#include <bits/stdc++.h>

using namespace std;

void check(int i, int j, vector<vector<bool> > &visited, queue<pair<int, int> > &q, vector<vector<int> > &map, pair<int, int> &pos, vector<vector<pair<int, int> > > &path){
	if(!visited[i][j]){
		if(map[i][j]==0){
			q.push(make_pair(i, j));
			visited[i][j]=1;
			path[i][j]=pos;
		}
	}
}

int solve(int m, int n){
	int ans=0, bomb_row_num;
	int index=1;
	vector<vector<bool> > visited;
	vector<vector<int> > map;
	queue<pair<int, int> > q; 
	vector<vector<pair<int, int> > > path;
	bool t=0;

	map.resize(m); visited.resize(m); path.resize(m);
	for(int i=0; i<m; ++i){
		for(int j=0; j<n; ++j){
			map[i].push_back(0);
			visited[i].push_back(t);
			path[i].push_back(make_pair(-1, -1));
		}
	}

	cin >> bomb_row_num;
	while(index++<=bomb_row_num){
		int row, bomb_num, pos;

		cin >> row >> bomb_num;
		while(bomb_num--){
			cin >> pos;

			map[row][pos]=1;
		}
	}
	int start_x, start_y, des_x, des_y;

	cin >> start_x >> start_y >> des_x >> des_y;

	q.push(make_pair(start_x, start_y));
	visited[start_x][start_y]=1;

	while(!q.empty()){
		pair<int, int> pos=q.front();
		q.pop();
		if(pos.first>0){
			check(pos.first-1, pos.second, visited, q, map, pos, path);
		}
		if(pos.first<m-1){
			check(pos.first+1, pos.second, visited, q, map, pos, path);
		}
		if(pos.second>0){
			check(pos.first, pos.second-1, visited, q, map, pos, path);
		}
		if(pos.second<n-1){
			check(pos.first, pos.second+1, visited, q, map, pos, path);
		}
	}

	while(path[des_x][des_y].first!=start_x || path[des_x][des_y].second!=start_y){
		pair<int, int> tmp=path[des_x][des_y];
		des_x=tmp.first;
		des_y=tmp.second;
		++ans;
	}

	return ans+1;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while(1){
		int m, n;

		cin >> m >> n;
		if(m==0 && n==0){
			return 0;
		}
		cout << solve(m, n) << '\n';
	}

	return 0;
}